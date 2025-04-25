/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:16:11 by eeravci           #+#    #+#             */
/*   Updated: 2025/04/25 18:58:44 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2(t_node **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_3(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

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
