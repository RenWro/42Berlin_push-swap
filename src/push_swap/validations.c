/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:40:49 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/24 22:17:23 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Validates that a string represents an integer within INT limits
static int	is_valid_int_range(char *nptr)
{
	long long	i;

	if (!ft_strisinteger(nptr))
		return (0);
	if (ft_strlen(nptr) > 11)
		return (0);
	i = ft_atoll(nptr);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	return (1);
}

// Allocates argument array depending on argc input form
static char	**build_args_array(int argc, char **argv)
{
	char	**tab;
	int		i;

	tab = NULL;
	if (argc == 2 && ft_strlen(argv[1]))
		tab = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		tab = ft_calloc(argc, sizeof(char *));
		if (!tab)
			errors(malloc_error);
		i = 0;
		while (++i < argc)
		{
			tab[i - 1] = ft_strdup(argv[i]);
			if (!tab[i - 1])
				clear_tab(tab);
		}
	}
	if (!tab)
		errors(malloc_error);
	return (tab);
}

// Main entry: validates arguments, converts, and checks edge cases
char	**validate_args(int argc, char **argv)
{
	int		i;
	char	**tab;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	tab = build_args_array(argc, argv);
	i = 0;
	while (tab[i])
	{
		if (!is_valid_int_range(tab[i]))
		{
			clear_tab(tab);
			errors(integer_overflow);
		}
		i++;
	}
	return (tab);
}

// Searches for duplicate integers in stack A
void	find_duplicates(t_stacks *stacks)
{
	t_list	*el;
	t_list	*el2;
	t_fl	*stack_a;

	stack_a = stacks->a;
	el = stack_a->first;
	while (el)
	{
		el2 = el->next;
		while (el2)
		{
			if (*(int *)el->content == *(int *)el2->content)
				clear_stacks(stacks, duplicated_value);
			el2 = el2->next;
		}
		el = el->next;
	}
}
