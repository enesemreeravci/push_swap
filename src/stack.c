/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:03:25 by eeravci           #+#    #+#             */
/*   Updated: 2025/04/06 13:15:56 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error_exit();
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_stack_bottom(t_node **stack, t_node *new)
{
	t_node	*temp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->stack;
	temp->next = new;
}

int	stack_size(t_node *stack)
{
	int size;
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}