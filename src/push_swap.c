/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:38:07 by eeravci           #+#    #+#             */
/*   Updated: 2025/04/17 14:43:45 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	// validate input and build stack_a as a linked list
	stack_a = parse_and_fill_stack(argc, argv, &count);
	// if it's already sorted, skip everything
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	// replace real values with their index position - helps radix sort
	normalize_stack(stack_a, count);
	// choose the right algorithm based on number count
	if (count <= 5)
		sort_small(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
	// prevent memory leaks
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
