/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:06:45 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/24 21:41:51 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Removes top two elements and swaps their positions
static void	swap(t_fl *stack)
{
	t_list	*top1;
	t_list	*top2;

	if (stack && stack->size > 1)
	{
		top1 = ft_lstpop(stack, 0);
		top2 = ft_lstpop(stack, 0);
		ft_lstadd_front(stack, top1);
		ft_lstadd_front(stack, top2);
	}
}

void	sa(t_stacks *stacks)
{
	swap(stacks->a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
	ft_putstr_fd("ss\n", 1);
}
