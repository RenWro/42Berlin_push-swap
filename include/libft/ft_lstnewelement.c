/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewelement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:53:40 by rwrobles          #+#    #+#             */
/*   Updated: 2025/03/18 16:56:54 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewelement(void *content)
{
	t_list	*el;

	el = ft_calloc(1, sizeof(t_list));
	if (!el)
		return (NULL);
	el->content = content;
	el->next = NULL;
	el->prev = NULL;
	return (el);
}
