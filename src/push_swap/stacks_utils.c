/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:21:22 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/24 21:36:44 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Calculates the distance from the top to a specific element in the stack
unsigned int	el_top_dist(t_list *top, t_list *el)
{
	unsigned int	dist;

	dist = 0;
	while (top && top != el)
	{
		dist++;
		top = top->next;
	}
	return (dist);
}

// Updates a_min and a_max pointers based on values in stack A
void	a_properties(t_stacks *stacks)
{
	t_list	*el;

	el = stacks->a->first;
	stacks->a_max = el;
	stacks->a_min = el;
	el = el->next;
	while (el)
	{
		if (el_int(el) > el_int(stacks->a_max))
			stacks->a_max = el;
		else if (el_int(el) < el_int(stacks->a_min))
			stacks->a_min = el;
		el = el->next;
	}
}

// Updates b_min and b_max pointers based on values in stack B
void	b_properties(t_stacks *stacks)
{
	t_list	*el;

	el = stacks->b->first;
	stacks->b_max = el;
	stacks->b_min = el;
	el = el->next;
	while (el)
	{
		if (el_int(el) > el_int(stacks->b_max))
			stacks->b_max = el;
		else if (el_int(el) < el_int(stacks->b_min))
			stacks->b_min = el;
		el = el->next;
	}
}

// Debug function: prints movement data calculated for a candidate element
void	print_el_data(t_el_data *data)
{
	const char	*names[] = {
		"rr + ra + rb",
		"rrr + rra + rrb",
		"ra + rrb",
		"rra + rb"
	};

	if (!data)
		return (0);
	printf("Candidate: %d\n", el_int(data->el));
	printf("  ra: %u\n", data->ra);
	printf("  rra: %u\n", data->rra);
	printf("  rb: %u\n", data->rb);
	printf("  rrb: %u\n", data->rrb);
	printf("  rr: %u\n", data->rr);
	printf("  rrr: %u\n", data->rrr);
	printf("  ra_net: %u\n", data->ra_net);
	printf("  rb_net: %u\n", data->rb_net);
	printf("  rra_net: %u\n", data->rra_net);
	printf("  rrb_net: %u\n", data->rrb_net);
	printf("  Total Moves: %u\n", data->moves);
	if (data->move_scheme >= 0 && data->move_scheme <= 3)
		printf("  Strategy: %s\n", names[data->move_scheme]);
	else
		printf("  Strategy: UNKNOWN\n");
}
