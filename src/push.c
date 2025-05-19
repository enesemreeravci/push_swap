/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:12:08 by eeravci           #+#    #+#             */
/*   Updated: 2025/05/15 10:44:10 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
pushes the top element from stack A to B
and prints "pb"
*/
void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

/*
pushes the top element from stack B to stack A
 and prints "pa"
*/
void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*a)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}
