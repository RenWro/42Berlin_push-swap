/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:09:27 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/24 21:36:52 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates the rotation count (rb) needed to place value_to_push in the 
//correct position in stack B
static unsigned int	rb_moves_edge(t_stacks *stacks, int value_to_push)
{
	t_list			*el;
	unsigned int	pos;

	el = stacks->b->first;
	pos = 0;
	while (el)
	{
		if (value_to_push > el_int(stacks->b_max) && el == stacks->b_max)
			break ;
		if (value_to_push < el_int(stacks->b_min) && el == stacks->b_min)
		{
			pos++;
			break ;
		}
		pos++;
		el = el->next;
	}
	return (pos);
}

// Calculates the position (rb) in B where value_to_push should be inserted
static unsigned int	rb_moves(t_stacks *stacks, int value_to_push)
{
	t_list			*el;
	t_list			*prev_el;
	unsigned int	pos;

	pos = 0;
	if (value_to_push > el_int(stacks->b_max)
		|| value_to_push < el_int(stacks->b_min))
		return (rb_moves_edge(stacks, value_to_push));
	el = stacks->b->first;
	while (el)
	{
		if (el->prev)
			prev_el = el->prev;
		else
			prev_el = stacks->b->last;
		if (el != stacks->b_max && el_int(prev_el)
			> value_to_push && el_int(el) < value_to_push)
			break ;
		pos++;
		el = el->next;
	}
	return (pos);
}

// Chooses the best move strategy based on total move cost
static void	min_moves(t_el_data *data)
{
	unsigned int	moves;
	unsigned int	_moves;

	moves = data->rr + data->ra_net + data->rb_net;
	data->move_scheme = rr_ra_rb;
	_moves = ft_min(moves, data->rrr + data->rra_net + data->rrb_net);
	if (_moves < moves)
	{
		moves = _moves;
		data->move_scheme = rrr_rra_rrb;
	}
	_moves = ft_min(moves, data->ra + data->rrb);
	if (_moves < moves)
	{
		moves = _moves;
		data->move_scheme = ra_rrb;
	}
	_moves = ft_min(moves, data->rra + data->rb);
	if (_moves < moves)
	{
		moves = _moves;
		data->move_scheme = rra_rb;
	}
	data->moves = moves;
}

// Computes the movement data for a single element and returns the 
//best among previous and current
t_el_data	*n_moves(t_stacks *stacks, t_list *el_a, t_el_data *prev_min_moves)
{
	t_el_data	*data;

	data = ft_calloc(1, sizeof(t_el_data));
	if (!data)
		return (NULL);
	data->el = el_a;
	data->ra = el_top_dist(stacks->a->first, el_a);
	data->rra = stacks->a->size - data->ra;
	data->rb = rb_moves(stacks, el_int(el_a));
	data->rrb = stacks->b->size - data->rb;
	data->rr = ft_min(data->ra, data->rb);
	data->rrr = ft_min(data->rra, data->rrb);
	data->ra_net = data->ra - data->rr;
	data->rb_net = data->rb - data->rr;
	data->rra_net = data->rra - data->rrr;
	data->rrb_net = data->rrb - data->rrr;
	min_moves(data);
	if (!prev_min_moves || data->moves < prev_min_moves->moves)
	{
		free(prev_min_moves);
		return (data);
	}
	free(data);
	return (prev_min_moves);
}
