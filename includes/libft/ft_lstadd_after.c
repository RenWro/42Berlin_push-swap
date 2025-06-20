/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:22:42 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/18 14:59:07 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Inserts a new node el immediately after the given reference node 
ref in the linked list lst.

- If el is NULL, the function exits without making any changes.
- If ref is the tail of the list, el becomes the new last node.
- The prev and next pointers of both el and ref are adjusted to maintain 
proper linkage.
- The total node count of lst is increased by one. */

void	ft_lstadd_after(t_fl *lst, t_list *ref, t_list *el)
{
	if (!el)
		return ;
	if (lst->last == ref)
		lst->last = el;
	el->next = ref->next;
	if (el->next)
		el->next->prev = el;
	ref->next = el;
	el->prev = ref;
	lst->size++;
}
