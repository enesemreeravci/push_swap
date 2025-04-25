/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:57:26 by eeravci           #+#    #+#             */
/*   Updated: 2025/04/25 18:58:42 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
