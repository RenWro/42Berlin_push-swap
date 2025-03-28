/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:20:31 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/18 14:59:08 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Inserts a new node el right before the reference node ref in the 
linked list lst.
- If el is NULL, the function exits without modifying the list.
- If ref is the head of the list, el becomes the new first node.
- The prev and next pointers of both el and ref are updated to 
preserve proper linkage.
- The total number of nodes in lst is increased by one. */

void	ft_lstadd_before(t_fl *lst, t_list *ref, t_list *el)
{
	if (!el)
		return ;
	if (lst->first == ref)
		lst->first = el;
	el->prev = ref->prev;
	if (el->prev)
		el->prev->next = el;
	ref->prev = el;
	el->next = ref;
	lst->size++;
}
