/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:38:09 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/24 21:37:01 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Moves the given element to the top of stack A using shortest rotation path
void	deliver_on_top_a(t_stacks *stacks, t_list *el_to_deliver)
{
	unsigned int	top_dist;
	unsigned int	bottom_dist;

	top_dist = el_top_dist(stacks->a->first, el_to_deliver);
	bottom_dist = stacks->a->size - top_dist;
	if (top_dist <= bottom_dist)
		while (top_dist--)
			ra(stacks);
	else
		while (bottom_dist--)
			rra(stacks);
}

// Finds the correct insert position in A for a given value, then 
//rotates A to bring that position to the top
static void	find_and_deliver(t_stacks *stacks, int value_to_push)
{
	t_list	*el;
	t_list	*next_el;

	el = stacks->a->first;
	next_el = el->next;
	while (el)
	{
		next_el = el->next;
		if (!next_el)
			next_el = stacks->a->first;
		if (el_int(el) < value_to_push && el_int(next_el) > value_to_push)
			break ;
		el = el->next;
	}
	deliver_on_top_a(stacks, next_el);
}

// Moves the top of stack B back into stack A in the correct sorted position
void	stack_back_to_a(t_stacks *stacks, int value_to_push)
{
	if (value_to_push > el_int(stacks->a_max))
	{
		deliver_on_top_a(stacks, stacks->a_min);
		stacks->a_max = stacks->b->first;
	}
	else if (value_to_push < el_int(stacks->a_min))
	{
		deliver_on_top_a(stacks, stacks->a_min);
		stacks->a_min = stacks->b->first;
	}
	else
		find_and_deliver(stacks, value_to_push);
	pa(stacks);
}
