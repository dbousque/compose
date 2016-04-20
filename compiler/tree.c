

#include "tree.h"

t_node	*new_node(char action, t_node *left, t_node *right, char *repr, char type)
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

char	*type_to_str(char type)
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
	else
	{
		printf("UNKNOWN TYPE !!!\n");
		exit(1);
	}
}