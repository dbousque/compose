

#ifndef TREE_H
# define TREE_H

# define INTEGER 1
# define STRING 2
# define ASSIGNEMENT 3
# define FLOATING 4
# define DOUBLE 5
# define LONG 6
# define VARIABLE 7
# define CHAR 8
# define LIST 9
# define FUNCTION 10
# define INDEX 11
# define ARGUMENTS 12

#include "../utils/utils.h"
#include <stdio.h>

typedef struct		s_node
{
	char			action;
	struct s_node	*left;
	struct s_node	*right;
	char			*repr;
	char			type;
}					t_node;

t_node	*new_node(char action, t_node *left, t_node *right, char *repr, char type);
void	print_tree(t_node *node);

#endif