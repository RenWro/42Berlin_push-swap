/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:47:47 by rwrobles          #+#    #+#             */
/*   Updated: 2025/06/20 14:59:04 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (!ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	validate_args(int ac, char **av)
{
	char	**tokens;
	int		i;
	int		j;

	i = 1;
	if (ac < 2)
		cleanup_and_exit(NULL, "");
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (!tokens || !tokens[0])
			cleanup_and_exit(NULL, "Error\n");
		j = 0;
		while (tokens[j])
		{
			if (!is_valid_number(tokens[j]))
				cleanup_and_exit(NULL, "Error\n");
			j++;
		}
		free_split(tokens);
		i++;
	}
}

void	join_args(int ac, char **av, t_stack *stack)
{
	char	*temp1;
	char	*temp2;
	int		i;

	i = 0;
	temp2 = ft_strdup("");
	while (++i < ac && av[i] != NULL)
	{
		temp1 = ft_strjoin(temp2, av[i]);
		if (temp2)
			free(temp2);
		if (i != ac - 1)
		{
			temp2 = ft_strjoin(temp1, " ");
			if (temp1)
				free(temp1);
			temp1 = temp2;
		}
	}
	stack->receive_args = ft_strdup(temp1);
	if (stack->receive_args == NULL)
		cleanup_and_exit(stack, "Error\n");
	if (temp1)
		free(temp1);
}

void	normalize_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	k;
	int	*temp;

	temp = malloc(stack->sizea * sizeof(*temp));
	if (temp == NULL)
		cleanup_and_exit(stack, "Error\n");
	i = -1;
	while (++i < stack->sizea)
	{
		k = 0;
		j = -1;
		while (++j < stack->sizea)
			if (stack->a[i] > stack->a[j])
				k++;
		temp[i] = k;
	}
	i = stack->sizea;
	while (i--)
		stack->a[i] = temp[i];
	free(temp);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	validate_args(ac, av);
	stack = malloc(sizeof * stack);
	if (stack == NULL)
		exit(1);
	init_stack(ac, av, stack);
	join_args(ac, av, stack);
	parse_args(stack);
	validate_stack(stack, 0);
	normalize_stack(stack);
	if (stack->sizea <= 1)
		cleanup_and_exit(stack, NULL);
	if (stack->sizea == 2 && stack->a[0] > stack->a[1])
		op_swap("sa", stack);
	else if (stack->sizea == 3)
		sort_3(stack);
	else if (stack->sizea == 4 || stack->sizea == 5)
		sort_4_5(stack);
	else
		radix_sort(stack);
	validate_stack(stack, 1);
	cleanup_and_exit(stack, NULL);
	return (0);
}
