#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct n_node	*next;
}					t_node;

t_node				*parse_and_fill_stack(int argc, char **argv, int *count);
#endif