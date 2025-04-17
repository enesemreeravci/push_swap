/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_fill_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eeravci <enes.nev@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:41:16 by eeravci           #+#    #+#             */
/*   Updated: 2025/04/17 14:44:11 by eeravci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_node	*parse_and_fill_stack(int argc, char **argv, int *count)
{
	char	**args;
	t_node	*stack;
	int		i;
	int		num;
	int		arg_mode;
	int		j;

	stack = NULL;
	i = 0;
	args = split_args(argc, argv, &arg_mode);
	*count = 0;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (is_duplicate(stack, num))
			error_exit();
		add_back(&stack, new_mode(num));
		(*count)++;
		i++;
	}
	if (arg_mode == 1)
	{
		j = 0;
		while (args[j])
			free(args[j++]);
		free(args);
	}
	return (stack);
}
