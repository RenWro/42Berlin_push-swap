/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:29:41 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/27 12:37:38 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack_a(t_stacks *stacks, char **tab)
{
	t_list	*el;
	int		*nb;
	int		i;

	i = 0;
	while (tab[i])
	{
		nb = malloc(sizeof(int));
		if (!nb)
			clear_stacks(stacks, malloc_error);
		*nb = ft_atoi(tab[i++]);
		el = ft_lstnewelement((void *)nb);
		if (!el)
			clear_stacks(stacks, malloc_error);
		ft_lstadd_back(&stacks->a->first, el);
	}
}

int	main(int argc, char **argv)
{
	char		**tab;
	t_stacks	stacks;

	tab = validate_args(argc, argv);
	ft_bzero(&stacks, sizeof(t_stacks));
	stacks.a = ft_calloc(1, sizeof(t_fl));
	stacks.b = ft_calloc(1, sizeof(t_fl));
	if (!stacks.a || !stacks.b)
		clear_stacks(&stacks, malloc_error);
	fill_stack_a(&stacks, tab);
	clear_tab(tab);
	find_duplicates(&stacks);
	algo(&stacks);
	clear_stacks(&stacks, not_error);
	return (0);
}
