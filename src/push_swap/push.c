/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:41:24 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/27 12:52:33 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_fl *from, t_fl *to)
{
	t_list	*el_from;

	if (from->size >= 1)
	{
		el_from = ft_lstpop(from, 0);
		ft_lstadd_front(&to->first, el_from);
		from->size--;
		to->size++;
	}
}

void	pa(t_stacks *stacks)
{
	push(stacks->b, stacks->a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *stacks)
{
	push(stacks->a, stacks->b);
	ft_putstr_fd("pb\n", 1);
}
