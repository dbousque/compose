

#include "tree.h"

t_node	*new_node(char action, t_node *left, t_node *right, char *repr, int type)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
	{
		exit(1);
	}
	node->action = action;
	node->left = left;
	node->right = right;
	node->type = type;
	if (!left && !right)
		node->repr = ft_strdup(repr);
	return (node);
}

t_sub_elt	*new_sub_elt(void *elt, char type)
{
	t_sub_elt	*sub_elt;

	if (!(sub_elt = (t_sub_elt*)malloc(sizeof(t_sub_elt))))
		malloc_error();
	sub_elt->type = type;
	sub_elt->elt = elt;
	return (sub_elt);
}

char	*type_to_str(int type)
{
	if (type == INTEGER)
		return (ft_strdup("INTEGER"));
	else if (type == STRING)
		return (ft_strdup("STRING"));
	else if (type == FLOATING)
		return (ft_strdup("FLOATING"));
	else if (type == DOUBLE)
		return (ft_strdup("DOUBLE"));
	else if (type == LONG)
		return (ft_strdup("LONG"));
	else if (type == CHAR)
		return (ft_strdup("CHAR"));
	else if (type >= 100000)
		return (ft_strjoin(type_to_str(type - 100000), "[ARR]"));
}

void	print_tree(t_node *node)
{
	if (node->action == INTEGER)
		printf("%s(INTEGER)", node->repr);
	else if (node->action == STRING)
		printf("%s(STRING)", node->repr);
	else if (node->action == FLOATING)
		printf("%s(FLOATING)", node->repr);
	else if (node->action == DOUBLE)
		printf("%s(DOUBLE)", node->repr);
	else if (node->action == LONG)
		printf("%s(LONG)", node->repr);
	else if (node->action == CHAR)
		printf("%s(CHAR)", node->repr);
	else if (node->action == INDEX)
	{
		printf("INDEX(");
		print_tree(node->right);
		printf(" OF ");
		print_tree(node->left);
		printf(")");
	}
	else if (node->action == FUNCTION)
	{
		printf("%s(FUNCTION)(", node->left->repr);
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == ARGUMENTS)
	{
		if (node->left)
		{
			print_tree(node->left);
			printf(", ");
		}
		print_tree(node->right);
	}
	else if (node->action == VARIABLE)
	{
		if (node->type)
			printf("%s(VARIABLE/TYPE:%s)", node->repr, type_to_str(node->type));
		else
			printf("%s(VARIABLE)", node->repr);
	}
	else if (node->action == ASSIGNEMENT)
	{
		print_tree(node->left);
		printf(" = ");
		print_tree(node->right);
	}
	else if (node->action == ADD)
	{
		printf("ADD(");
		print_tree(node->left);
		printf(", ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == MINUS)
	{
		printf("MINUS(");
		print_tree(node->left);
		printf(", ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == DIVIDE)
	{
		printf("DIVIDE(");
		print_tree(node->left);
		printf(", ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == MULTIPL)
	{
		printf("MULTIPL(");
		print_tree(node->left);
		printf(", ");
		print_tree(node->right);
		printf(")");
		//else if (node->action == LIST)
		//printf("[LIST/TYPE:%s]", type_to_str(node->type));
	}
	else if (node->action == SLICE)
	{
		printf("[SLICE/");
		print_tree(node->left);
		printf(" -> ");
		print_tree(node->right);
		printf("]");
	}
	else if (node->action == SLICE_INDEXES)
	{
		print_tree(node->left);
		printf(" : ");
		print_tree(node->right);
	}
	else if (node->action == CONDITION)
	{
		printf("IF(");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == WHILE_LOOP)
	{
		printf("WHILE(");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == FOR_LOOP1)
	{
		printf("FOR(");
		print_tree(node->left);
		printf(" -> ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == FOR_LOOP2)
	{
		printf("FOR(");
		print_tree(node->left);
		printf(" IN ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == EQUALITY_CHECK)
	{
		printf("IS_EQUAL(");
		print_tree(node->left);
		printf(", ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == GREATER_THAN)
	{
		printf("IS_GREATER(");
		print_tree(node->left);
		printf(", ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == SMALLER_THAN)
	{
		printf("IS_SMALLER(");
		print_tree(node->left);
		printf(", ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == GREATER_EQUAL)
	{
		printf("IS_GREATER_EQ(");
		print_tree(node->left);
		printf(", ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == SMALLER_EQUAL)
	{
		printf("IS_SMALLER_EQ(");
		print_tree(node->left);
		printf(", ");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == RETURN)
	{
		printf("RETURN -> ");
		print_tree(node->right);
	}
	else if (node->action == PRIORITY)
	{
		printf("PRIO(");
		print_tree(node->right);
		printf(")");
	}
	else if (node->action == FUNCTION_DECL)
	{
		printf("%s(FUNCTION_DECL)(", node->left->repr);
		if (node->right)
			print_tree(node->right);
		printf(")");
		if (node->type)
			printf("RET_TYPE->%s", type_to_str(node->type));
	}
	else if (node->action == FUNCTION_ARGS)
	{
		if (node->left)
		{
			print_tree(node->left);
			printf(", ");
		}
		print_tree(node->right);
	}
	else
	{
		printf("UNKNOWN TYPE !!!\n");
		exit(1);
	}
}

void	print_tree_indent(t_node *node, int indentation)
{
	while (indentation > 0)
	{
		printf("\t");
		indentation--;
	}
	print_tree(node);
}