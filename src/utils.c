/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:24:23 by eeravci           #+#    #+#             */
/*   Updated: 2025/05/17 23:33:11 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// prints error to standard error and exits he program
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// returns 1 if the value already exists in the stack, otherwise 0
int	is_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// validates if the given string is a correctly formatted integer
int	ft_isnumbervalid(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int ft_number_range(char *str)
{
	long num = ft_atoi(str);
	
	if(num > INT_MAX || num < INT_MIN)
		return 1;
	return 0;
}

// frees all nodes in the stack and clears the pointer
void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
