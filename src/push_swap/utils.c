/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:32:12 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/27 12:16:53 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_min(unsigned int a, unsigned int b)
{
	if (a < b)
		return (a);
	return (b);
}

unsigned int	ft_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	**clear_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

void	clear_stacks(t_stacks *stacks, int error)
{
	if (stacks->a)
		ft_lstclear(&stacks->a->first, free);
	if (stacks->b)
		ft_lstclear(&stacks->b->first, free);
	free(stacks->a);
	free(stacks->b);
	errors(error);
}

void	errors(int error_code)
{
	(void)error_code;
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
