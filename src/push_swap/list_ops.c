/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:48:51 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/27 12:48:55 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_first_or_last(t_fl *lst, t_list *el)
{
	if (el == lst->first)
	{
		lst->first = el->next;
		if (lst->first)
			lst->first->prev = NULL;
	}
	if (el == lst->last)
	{
		lst->last = el->prev;
		if (lst->last)
			lst->last->next = NULL;
	}
}

t_list	*ft_lstpop(t_fl *lst, int index)
{
	t_list	*el;

	el = ft_lstpickel(lst, index);
	if (!el)
		return (NULL);
	if (el != lst->first && el != lst->last)
	{
		el->prev->next = el->next;
		el->next->prev = el->prev;
	}
	else
		update_first_or_last(lst, el);
	el->next = NULL;
	el->prev = NULL;
	lst->size--;
	return (el);
}
