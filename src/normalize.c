/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:35:38 by eeravci           #+#    #+#             */
/*   Updated: 2025/04/17 14:44:18 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	int	temp;

	int i, j;
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

int	get_index(int *sorted, int value, int size)
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
	while (stacl)
	{
		stack->value = get_index(sorted, stack->value,
				count) stack = stack->next;
	}
	free(sorted);
}
