/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:29:47 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/24 21:39:15 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Moves the top element to the bottom of the stack
static void	rotate(t_fl *stack)
{
	t_fl	*first;

	if (stack && stack->size > 1)
	{
		first = ft_lstpop(stack, 0);
		ft_lstadd_back(stack, first);
	}
}

void	ra(t_stacks *stacks)
{
	rotate(stacks->a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stacks *stacks)
{
	rotate(stacks->b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stacks *stacks)
{
	rotate(stacks->a);
	rotate(stacks->b);
	ft_putstr_fd("rr\n", 1);
}
