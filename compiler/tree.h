

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
# define LIST 100000
# define FUNCTION 10
# define INDEX 11
# define ARGUMENTS 12
# define ADD 13
# define MINUS 14
# define DIVIDE 15
# define MULTIPL 16
# define SLICE 17
# define SLICE_INDEXES 18
# define CONDITION 19
# define WHILE_LOOP 20
# define FOR_LOOP1 21
# define FOR_LOOP2 22
# define EQUALITY_CHECK 23
# define GREATER_THAN 24
# define GREATER_EQUAL 25
# define SMALLER_THAN 26
# define SMALLER_EQUAL 27
# define RETURN 28
# define PRIORITY 29
# define FUNCTION_DECL 30
# define FUNCTION_ARGS 31

# define INDENT_BLOCK 32
# define INSTRUCTION 33

#include "../utils/utils.h"
#include "tree.h"
#include <stdio.h>

typedef struct		s_node
{
	char			action;
	struct s_node	*left;
	struct s_node	*right;
	char			*repr;
	int       type;
}					t_node;

typedef struct		s_sub_elt
{
	char			type;
	void			*elt;
}					t_sub_elt;

t_node	*new_node(char action, t_node *left, t_node *right, char *repr, int type);
void	print_tree(t_node *node);
void	print_tree_indent(t_node *node, int indentation);
t_sub_elt	*new_sub_elt(void *elt, char type);

#endif