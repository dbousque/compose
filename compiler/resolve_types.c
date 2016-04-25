

#include "build_tree.h"

void	add_function_args(t_linked_list *function, t_linked_list *variables)
{
	t_node			*tmp_node;

	// prototype, get the arguments
	tmp_node = ((t_node*)((t_sub_elt*)function->elts[0])->elt);
	tmp_node = tmp_node->right;
	while (tmp_node)
	{
		if (tmp_node->action == VARIABLE)
			add_to_list(variables, tmp_node);
		else
			add_to_list(variables, tmp_node->right);
		tmp_node = tmp_node->left;
	}
}

char	var_in_list(char *var_name, t_linked_list *variables)
{
	int		i;

	i = 0;
	while (i < variables->len)
	{
		if (ft_strcmp(var_name, ((t_node*)variables->elts[i])->repr) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	is_value(char action)
{
	if (action == INTEGER || action == FLOATING || action == LONG || action == DOUBLE || action == STRING || action == CHAR)
		return (1);
	return (0);
}

char	is_operation(char action)
{
	if (action == ADD || action == MINUS || action == DIVIDE || action == MULTIPL)
		return (1);
	return (0);
}

char	in_chartab(int type, char numbers[])
{
	int		i;

	i = 0;
	while (numbers[i])
	{
		if (numbers[i] == type)
			return (1);
		i++;
	}
	return (0);
}

int		take_highest_number(int type1, int type2, char numbers[])
{
	int 	i;

	i = 0;
	while (numbers[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (type1 == numbers[i])
			return (type1);
		if (type2 == numbers[i])
			return (type2);
		i--;
	}
	return (0);
}

int		different_types_merge(int type1, int type2, char operation)
{
	char	numbers[] = {CHAR, INTEGER, LONG, FLOATING, DOUBLE, 0};

	if (in_chartab(type1, numbers) && in_chartab(type2, numbers))
		return (take_highest_number(type1, type2, numbers));
	if (operation == ADD && type1 == STRING && type2 == STRING)
		return (STRING);
	if (operation == ADD && type1 == STRING && type2 == CHAR)
		return (STRING);
	return (0);
}

void	resolve_expression(t_linked_list *syntax_tree, t_node *expr, t_linked_list *variables)
{
	int		tmp_type1;
	int		tmp_type2;

	if (expr->action == ASSIGNEMENT)
	{
		resolve_expression(syntax_tree, expr->right, variables);
		if (!expr->left->type || expr->left->type == expr->right->type)
			expr->left->type = expr->right->type;
		else
		{
			ft_putstr("Trying to assign from incompatible types.\n");
			exit(1);
		}
		if (!var_in_list(expr->left->repr, variables))
			add_to_list(variables, expr->left);
	}
	else if (is_operation(expr->action))
	{
		resolve_expression(syntax_tree, expr->left, variables);
		resolve_expression(syntax_tree, expr->right, variables);
		expr->type = different_types_merge(expr->left->type, expr->right->type, expr->action);
	}
	else if (expr->action == PRIORITY)
	{
		resolve_expression(expr->right);
		expr->type = expr->right->type;
	}
}

void	resolve_indent_block(t_linked_list *syntax_tree, t_linked_list *block, t_linked_list *variables)
{
	(void)syntax_tree;
	(void)block;
	(void)variables;
}

void	resolve_function(t_linked_list *syntax_tree, t_linked_list *function)
{
	t_linked_list	*variables;
	int				i;

	variables = new_list();
	add_function_args(function, variables);
	i = 0;
	while (i < function->len)
	{
		// if it's an indent block
		if (((t_sub_elt*)function->elts[i])->type == INDENT_BLOCK)
			resolve_indent_block(syntax_tree, ((t_sub_elt*)function->elts[i])->elt, variables);
		else
			resolve_expression(syntax_tree, ((t_sub_elt*)function->elts[i])->elt, variables);
		i++;
	}
	printf("\nARGS:\n");
	i = 0;
	while (i < variables->len)
	{
		print_tree(variables->elts[i]);
		printf("\n");
		i++;
	}
}

void	resolve_types(t_linked_list *syntax_tree)
{
	int   i;

	i = 0;
	while (i < syntax_tree->len)
	{
		resolve_function(syntax_tree, ((t_linked_list*)((t_sub_elt*)syntax_tree->elts[i])->elt));
		i++;
	}
}