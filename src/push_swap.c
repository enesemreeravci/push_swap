/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:38:07 by eeravci           #+#    #+#             */
/*   Updated: 2025/05/01 16:56:29 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	i = 0;
	stack_a = parse_and_fill_stack(argc, argv, &count);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	normalize_stack(stack_a, count);
	if (count <= 5)
		sort_small(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
