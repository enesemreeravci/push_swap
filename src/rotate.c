/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:16:35 by eeravci           #+#    #+#             */
/*   Updated: 2025/04/11 21:19:43 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **stack)
{
	t_node *first;
	t_node *last;

	if (!*stack || !(*stack)->next)
		return ;
    first = *stack;
    *stack = first->next;
    first->next = NULL;

    last = *stack;
    while(last->next)
        last = last->next;
    last->next = first;
    write(1, "ra\n", 3);
}