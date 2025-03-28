/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 10:34:54 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/24 21:36:19 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Executes optimized rotations where ra/rb or rra/rrb overlap (using rr/rrr)
static void	move_a_to_b_combined_cases(t_stacks *stacks, t_el_data *data)
{
	if (data->move_scheme == rr_ra_rb)
	{
		while (data->rr--)
			rr(stacks);
		while (data->ra_net--)
			ra(stacks);
		while (data->rb_net--)
			rb(stacks);
	}
	else if (data->move_scheme == rrr_rra_rrb)
	{
		while (data->rrr--)
			rrr(stacks);
		while (data->rra_net--)
			rra(stacks);
		while (data->rrb_net--)
			rrb(stacks);
	}
}

// Executes separate rotations when directions differ
static void	move_a_to_b_not_combined_cases(t_stacks *stacks, t_el_data *data)
{
	if (data->move_scheme == ra_rrb)
	{
		while (data->ra--)
			ra(stacks);
		while (data->rrb--)
			rrb(stacks);
	}
	else if (data->move_scheme == rra_rb)
	{
		while (data->rra--)
			rra(stacks);
		while (data->rb--)
			rb(stacks);
	}
}

void	move_a_to_b(t_stacks *stacks, t_el_data *data)
{
	if (!data)
		return ;
	move_a_to_b_combined_cases(stacks, data);
	move_a_to_b_not_combined_cases(stacks, data);
	pb(stacks);
	if (el_int(data->el) > el_int(stacks->b_max))
		stacks->b_max = stacks->b->first;
	else if (el_int(data->el) < el_int(stacks->b_min))
		stacks->b_min = stacks->b->first;
	free(data);
}
