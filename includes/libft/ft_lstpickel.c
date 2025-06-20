/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpickel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:10:11 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/18 17:11:18 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns an element from a linked list at the specified index.
 */
t_list	*ft_lstpickel(t_fl *lst, int index)
{
	t_list	*el;

	if ((!lst) || (index < 0 && - index > (int)lst->size)
		|| (index >= 0 && index + 1 > (int)lst->size))
		return (NULL);
	if (index < 0)
	{
		el = lst->last;
		while (++index)
			el = el->prev;
	}
	else
	{
		el = lst->first;
		while (index--)
			el = el->next;
	}
	return (el);
}
