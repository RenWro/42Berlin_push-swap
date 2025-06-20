/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:38:35 by rwrobles          #+#    #+#             */
/*   Updated: 2025/06/20 14:02:23 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(char *type, t_stack *stack)
{
	long	tmp;

	if (!type || !stack)
		return ;
	if (!ft_strncmp(type, "sa", 2) && stack->sizea > 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
		ft_putendl_fd("sa", 1);
	}
	else if (!ft_strncmp(type, "sb", 2) && stack->sizeb > 1)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
		ft_putendl_fd("sb", 1);
	}
}

void	op_push(char *type, t_stack *stack)
{
	long	tmp;

	if (!type || !stack)
		return ;
	if (ft_strncmp(type, "pa", 3) == 0 && stack->sizeb > 0)
	{
		tmp = stack->b[0];
		ft_memmove(stack->a + 1, stack->a, sizeof(long) * stack->sizea);
		stack->a[0] = tmp;
		stack->sizeb--;
		ft_memmove(stack->b, stack->b + 1, sizeof(long) * stack->sizeb);
		stack->sizea++;
	}
	else if (ft_strncmp(type, "pb", 3) == 0 && stack->sizea > 0)
	{
		tmp = stack->a[0];
		ft_memmove(stack->b + 1, stack->b, sizeof(long) * stack->sizeb);
		stack->b[0] = tmp;
		stack->sizea--;
		ft_memmove(stack->a, stack->a + 1, sizeof(long) * stack->sizea);
		stack->sizeb++;
	}
	ft_putendl_fd(type, 1);
}

void	op_rotate(char *type, t_stack *stack)
{
	long	tmp;

	if (!type || !stack)
		return ;
	if (ft_strncmp(type, "ra", 2) == 0 && stack->sizea > 1)
	{
		tmp = stack->a[0];
		ft_memmove(stack->a, stack->a + 1, sizeof(long) * (stack->sizea - 1));
		stack->a[stack->sizea - 1] = tmp;
		ft_putendl_fd("ra", 1);
	}
	else if (ft_strncmp(type, "rb", 2) == 0 && stack->sizeb > 1)
	{
		tmp = stack->b[0];
		ft_memmove(stack->b, stack->b + 1, sizeof(long) * (stack->sizeb - 1));
		stack->b[stack->sizeb - 1] = tmp;
		ft_putendl_fd("rb", 1);
	}
}

void	op_reverse_rotate(char *type, t_stack *stack)
{
	long	tmp;

	if (!type || !stack)
		return ;
	if (ft_strncmp(type, "rra", 3) == 0 && stack->sizea > 1)
	{
		tmp = stack->a[stack->sizea - 1];
		ft_memmove(stack->a + 1, stack->a, sizeof(long) * (stack->sizea - 1));
		stack->a[0] = tmp;
		ft_putendl_fd("rra", 1);
	}
	else if (ft_strncmp(type, "rrb", 3) == 0 && stack->sizeb > 1)
	{
		tmp = stack->b[stack->sizeb - 1];
		ft_memmove(stack->b + 1, stack->b, sizeof(long) * (stack->sizeb - 1));
		stack->b[0] = tmp;
		ft_putendl_fd("rrb", 1);
	}
}
