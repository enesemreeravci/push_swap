/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:43:02 by eeravci           #+#    #+#             */
/*   Updated: 2025/04/21 17:06:03 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ─────────────── STRUCT ─────────────── */

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

/*-------------utils---------------*/

void				error_exit(void);

/* ──────────── STACK FUNCTIONS ───────────── */

t_node				*new_node(int value);
void				add_stack_bottom(t_node **stack, t_node *new);
int					stack_size(t_node *stack);
void				free_stack(t_node **stack);

/* ──────────── PARSING & INIT ───────────── */

t_node				*parse_and_fill_stack(int argc, char **argv, int *count);
int					is_duplicate(t_node *stack, int value);
long				ft_atoi_safe(const char *str);
int					ft_isdigit(int c);
void				free_stack(t_node **stack);
void				normalize_stack(t_node *stack, int count);
int					get_index(t_node *stack, int value);

/* ─────────────── SORTING ─────────────── */

void				sort_2(t_node **a);
void				sort_3(t_node **a);
void				sort_5(t_node **a, t_node **b);
void				sort_big(t_node **a, t_node **b);
int					is_sorted(t_node *stack);
void				normalize_stack(t_node *stack, int count);
void				sort_small(t_node **a, t_node **b);
int					get_array_index(int *sorted, int value, int size);

/* ─────────────── OPERATIONS ─────────────── */

// swap.c
void				sa(t_node **a);

// push.c
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);

// rotate.c
void				ra(t_node **a);

// reverse_rotate.c
void				rra(t_node **a);

#endif
