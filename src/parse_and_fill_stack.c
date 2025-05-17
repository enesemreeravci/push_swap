/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_fill_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <eeravci@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:41:16 by eeravci           #+#    #+#             */
/*   Updated: 2025/05/17 23:36:16 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**split_args(int argc, char **argv, int *arg_mode)
{
	if (argc == 2)
	{
		*arg_mode = 1;
		return (ft_split(argv[1], ' '));
	}
	else
	{
		*arg_mode = 0;
		return (&argv[1]);
	}
}

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static void	fill_stack(t_node **stack, char **args, int *count)
{
	int	num;
	int	i;

	i = 0;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (!ft_isnumbervalid(args[i]) || ft_number_range(args[i]))
		{
			free_stack(stack);
			error_exit();
		}
		if (is_duplicate(*stack, num))
			error_exit();
		add_stack_bottom(stack, new_node(num));
		(*count)++;
		i++;
	}
}

t_node	*parse_and_fill_stack(int argc, char **argv, int *count)
{
	char	**args;
	t_node	*stack;
	int		arg_mode;

	stack = NULL;
	args = split_args(argc, argv, &arg_mode);
	*count = 0;
	fill_stack(&stack, args, count);
	if (arg_mode == 1)
		free_args(args);
	return (stack);
}
