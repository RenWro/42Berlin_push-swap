/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:02:21 by rwrobles          #+#    #+#             */
/*   Updated: 2025/06/20 15:06:35 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	cleanup_and_exit(t_stack *stack, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (stack)
	{
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
		if (stack->receive_args)
			free(stack->receive_args);
		free(stack);
	}
	exit(1);
}
