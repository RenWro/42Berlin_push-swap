/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:01:26 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/24 21:37:08 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Takes the last element of the stack and moves it to the front
static void	rev_rotate(t_fl *stack)
{
	t_fl	*last;

	if (stack && stack->size > 1)
	{
		last = ft_lstpop(stack, -1);
		ft_lstadd_front(stack, last);
	}
}

void	rra(t_stacks *stacks)
{
	rev_rotate(stacks->a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stacks *stacks)
{
	rev_rotate(stacks->b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stacks *stacks)
{
	rev_rotate(stacks->a);
	rev_rotate(stacks->b);
	ft_putstr_fd("rrr\n", 1);
}
