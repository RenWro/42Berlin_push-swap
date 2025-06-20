/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:08:38 by rwrobles          #+#    #+#             */
/*   Updated: 2025/06/20 15:03:16 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_stack
{
	long	*a;
	long	*b;
	int		sizea;
	int		sizeb;
	char	*receive_args;
}			t_stack;

/* --- Free Split (from memory.c) --- */
void	free_split(char **split);

/* --- Operations (from ops.c) --- */
void	op_swap(char *type, t_stack *stack);
void	op_push(char *type, t_stack *stack);
void	op_rotate(char *type, t_stack *stack);
void	op_reverse_rotate(char *type, t_stack *stack);

/* --- Sorting (from sorts.c) --- */
void	sort_3(t_stack *stack);
void	sort_4_5(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
void	radix_sort(t_stack *stack);

/* --- Utils (from utils.c) --- */
void	validate_stack(t_stack *stack, int i);
long	ps_atol(const char *str);
void	parse_args(t_stack *stack);
int		count_split_tokens(char const *number, char c);
void	init_stack(int ac, char **av, t_stack *stack);

/* --- Main helpers (from main.c) --- */
void	cleanup_and_exit(t_stack *stack, char *msg);
void	validate_args(int ac, char **av);
void	normalize_stack(t_stack *stack);

#endif
