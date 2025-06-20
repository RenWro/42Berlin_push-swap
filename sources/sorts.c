/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:45:38 by rwrobles          #+#    #+#             */
/*   Updated: 2025/06/20 13:57:13 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->a[2] != 2)
	{
		if (stack->a[0] == 2)
			op_rotate("ra", stack);
		else
			op_reverse_rotate("rra", stack);
	}
	if (stack->a[0] > stack->a[1])
		op_swap("sa", stack);
}

void	sort_4_5(t_stack *stack)
{
	while (stack->sizeb < 2)
	{
		if (stack->a[0] == 0 || stack->a[0] == 1)
			op_push("pb", stack);
		else
			op_rotate("ra", stack);
	}
	if (stack->sizeb > 0 && stack->b[0] == 0)
		op_swap("sb", stack);
	if (stack->sizea > 2 && stack->a[2] != 4)
	{
		if (stack->a[0] == 4)
			op_rotate("ra", stack);
		else
			op_reverse_rotate("rra", stack);
	}
	if (stack->a[0] > stack->a[1])
		op_swap("sa", stack);
	op_push("pa", stack);
	op_push("pa", stack);
}

int	stack_is_sorted(t_stack *stack)
{
	int	i;

	if (stack->sizea <= 1)
		return (1);
	i = 0;
	while (i < stack->sizea - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	radix_b_to_a(t_stack *stack, int sizeb, int bit_size, int j)
{
	while (sizeb-- && j <= bit_size && !stack_is_sorted(stack))
	{
		if (stack->sizeb > 0 && ((stack->b[0] >> j) & 1) == 0)
			op_rotate("rb", stack);
		else
			op_push("pa", stack);
	}
	if (stack_is_sorted(stack))
		while (stack->sizeb != 0)
			op_push("pa", stack);
}

void	radix_sort(t_stack *stack)
{
	int		j;
	int		bit_size;
	int		size;

	bit_size = 0;
	size = stack->sizea;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack->sizea;
		while (size-- && !stack_is_sorted(stack))
		{
			if (((stack->a[0] >> j) & 1) == 0)
				op_push("pb", stack);
			else
				op_rotate("ra", stack);
		}
		radix_b_to_a(stack, stack->sizeb, bit_size, j + 1);
	}
	while (stack->sizeb != 0)
		op_push("pa", stack);
}
