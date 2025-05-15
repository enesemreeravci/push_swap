/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:19:12 by eeravci           #+#    #+#             */
/*   Updated: 2025/05/15 10:46:48 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
gets the number of bits needed to represent
the maximum value in the stack
*/
int	get_max_bits(t_node *stack)
{
	int	max;
	int	max_num;

	max = 0;
	max_num = 0;
	while (stack)
	{
		if (stack->value > max_num)
			max_num = stack->value;
		stack = stack->next;
	}
	while ((max_num >> max) != 0)
		max++;
	return (max);
}

// sorts large stack using binary radix sort based on normalized values
void	sort_big(t_node **a, t_node **b)
{
	int	i;
	int	size;
	int	j;
	int	max_bits;

	i = 0;
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->value >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
