/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:10:11 by rwrobles          #+#    #+#             */
/*   Updated: 2025/04/08 20:21:18 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_el_is_first(t_list *lst, t_element *el)
{
	lst->first = el->next;
	if (lst->first)
		lst->first->prev = NULL;
}

static void	ft_el_is_last(t_list *lst, t_element *el)
{
	lst->last = el->prev;
	if (lst->last)
		lst->last->next = NULL;
}

static t_element	*ft_lstpickel(t_list *lst, int index)
{
	t_element	*el;

	if (index < 0)
		index = lst->size + index;
	if (index < 0 || index >= lst->size)
		return (NULL);
	el = lst->first;
	while (index--)
		el = el->next;
	return (el);
}

t_element	*ft_lstpop(t_list *lst, int index)
{
	t_element	*el;

	if (!lst || lst->size == 0)
		return (NULL);
	el = ft_lstpickel(lst, index);
	if (!el)
		return (NULL);
	if (el != lst->first && el != lst->last)
	{
		el->prev->next = el->next;
		el->next->prev = el->prev;
	}
	else
	{
		if (el == lst->first)
			ft_el_is_first(lst, el);
		if (el == lst->last)
			ft_el_is_last(lst, el);
	}
	el->next = NULL;
	el->prev = NULL;
	lst->size--;
	return (el);
}
