/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rule_by_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:06:10 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/24 22:13:56 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts a stack of 2 elements
static void	stack_of_two(t_stacks *stacks)
{
	if (el_int(stacks->a->first) > el_int(stacks->a->last))
		sa(stacks);
}

// Sorts a stack of 3 elements using minimal operations
static void	stack_of_three(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = el_int(stacks->a->first);
	second = el_int(stacks->a->first->next);
	third = el_int(stacks->a->last);
	if (first < second && second < third)
		return ;
	else if (first < third && second > third)
	{
		rra(stacks);
		sa(stacks);
	}
	else if (first < third && second < first)
		sa(stacks);
	else if (first < second && third < first)
		rra(stacks);
	else if (first > third && second < third)
		ra(stacks);
	else if (first > second && second > third)
	{
		sa(stacks);
		rra(stacks);
	}
}

// Prepares a stack of 4 or 5 elements by pushing to B until A has 3 elements
static void	stack_of_five(t_stacks *stacks)
{
	while (stacks->a->size > 3 && stacks->b->size < 2)
		pb(stacks);
	b_properties(stacks);
	if (stacks->a->size == 3)
		stack_of_three(stacks);
}

// Selects sorting rule based on stack size (only for very small sizes)
void	stack_rule_by_size(t_stacks *stacks)
{
	if (stacks->a->size == 1)
		return ;
	if (stacks->a->size == 2)
	{
		stack_of_two(stacks);
		stacks->b_sorted = 1;
	}
	else if (stacks->a->size == 3)
	{
		stack_of_three(stacks);
		stacks->b_sorted = 1;
	}
	else if (!stacks->b_sorted)
		stack_of_five(stacks);
}
