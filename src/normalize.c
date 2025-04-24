/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:00:56 by eeravci           #+#    #+#             */
/*   Updated: 2025/04/24 12:31:26 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// this function does copy values into an array
int	*copy_to_array(t_node *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
	return (arr);
}

// a simple bubble sort
void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	get_array_index(int *sorted, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize_stack(t_node *stack, int count)
{
	int	*sorted;

	sorted = copy_to_array(stack, count);
	bubble_sort(sorted, count);
	while (stack)
	{
		stack->value = get_array_index(sorted, stack->value, count);
		stack = stack->next;
	}
	free(sorted);
}
