/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:43:20 by rwrobles          #+#    #+#             */
/*   Updated: 2025/06/20 13:59:50 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_stack(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stack->sizea)
		{
			j = i + 1;
			while (j < stack->sizea)
			{
				if (stack->a[i] == stack->a[j])
					cleanup_and_exit(stack, "Error\n");
				j++;
			}
			if (stack->a[i] > INT_MAX || stack->a[i] < INT_MIN)
				cleanup_and_exit(stack, "Error\n");
			i++;
		}
	}
	if (stack_is_sorted(stack))
		cleanup_and_exit(stack, NULL);
}

long	ps_atol(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

void	parse_args(t_stack *stack)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	temp = ft_split(stack->receive_args, ' ');
	if (temp == NULL)
		cleanup_and_exit(stack, "Error\n");
	i = 0;
	while (temp[i] != NULL && temp[i][0] != '\0')
	{
		if (stack->a != NULL)
		{
			stack->a[j] = ps_atol(temp[i]);
			j++;
		}
		free(temp[i]);
		i++;
	}
	free(temp);
}

int	count_split_tokens(char const *number, char c)
{
	int	count;

	count = 0;
	while (*number)
	{
		if (*number != c)
		{
			count++;
			while (*number && *number != c)
				number++;
		}
		else
			number++;
	}
	return (count);
}

void	init_stack(int ac, char **av, t_stack *stack)
{
	int	i;

	i = 1;
	stack->sizea = 0;
	stack->sizeb = 0;
	while (i < ac)
	{
		if (count_split_tokens(av[i], ' '))
			stack->sizea += count_split_tokens(av[i], ' ');
		else
			stack->sizea++;
		i++;
	}
	stack->a = malloc(stack->sizea * sizeof(*stack->a));
	if (stack->a == NULL)
		return ;
	stack->b = malloc(stack->sizea * sizeof(*stack->b));
	if (stack->b == NULL)
		return ;
}
