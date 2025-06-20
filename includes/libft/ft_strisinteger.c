/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisinteger.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:39:46 by rwrobles          #+#    #+#             */
/*   Updated: 2025/06/15 13:41:55 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <ctype.h>

bool	ft_strisinteger(const char *str)
{
	if (!str || *str == '\0')
		return (false);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (!isdigit((unsigned char)*str))
			return (false);
		str++;
	}
	return (true);
}
