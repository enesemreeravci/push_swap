/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:16:11 by eeravci           #+#    #+#             */
/*   Updated: 2025/05/15 10:49:47 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// get the position of a value in the stack
int	get_index(t_node *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

// find the lowest value in the stack
int	get_min_value(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	push_min_to_b(t_node **a, t_node **b)
{
	int	min;
	int	index;

	min = get_min_value(*a);
	index = get_index(*a, min);
	if (index == 1)
		ra(a);
	else if (index == 2)
	{
		ra(a);
		ra(a);
	}
	else if (index == 3)
		rra(a);
	else if (index == 4)
	{
		rra(a);
		rra(a);
	}
	pb(a, b);
}

void	sort_5(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		push_min_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		pa(a, b);
	}
}

void	sort_small(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4 || size == 5)
		sort_5(a, b);
}
