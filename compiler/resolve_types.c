

#include "build_tree.h"

extern t_linked_list *builtin_functions;

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

char	typeof_var_in_list(char *var_name, t_linked_list *variables)
{
	int		i;

	i = 0;
	while (i < variables->len)
	{
		if (ft_strcmp(var_name, ((t_node*)variables->elts[i])->repr) == 0)
			return (((t_node*)variables->elts[i])->type);
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

void	find_function_and_resolve(t_linked_list *syntax_tree, t_stack *previous_functions, t_node *function_call)
{
	// set the expression type to be the function return type
	if (is_builtin_function(function_call))
	{
		// just look the return type up
	}
	else
	{
		// look for this function is the syntax tree, and resolve the return type of it.
		// If stuck in a loop (function calls itself, we can see that if the function is already in the previous_functions),
		// then ignore the looping function call, and resolve all the rest. If the type of the return values can't be determined
		// after that, then exit and ask the user to specify the return type of the function 
	}
}

void	resolve_expression(t_linked_list *syntax_tree, t_stack *previous_functions, t_node *expr, t_linked_list *variables)
{
	int		tmp_type1;
	int		tmp_type2;

	if (!expr)
		return ;
	if (expr->action == ASSIGNEMENT)
	{
		resolve_expression(syntax_tree, previous_functions, expr->right, variables);
		if (!expr->left->type || expr->left->type == expr->right->type
				|| (var_in_list(expr->left->repr, variables) && typeof_var_in_list(expr->left->repr, variables) == expr->right->type))
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
		resolve_expression(syntax_tree, previous_functions, expr->left, variables);
		resolve_expression(syntax_tree, previous_functions, expr->right, variables);
		expr->type = different_types_merge(expr->left->type, expr->right->type, expr->action);
	}
	else if (expr->action == PRIORITY)
	{
		resolve_expression(syntax_tree, previous_functions, expr->right, variables);
		expr->type = expr->right->type;
	}
	else if (expr->action == FUNCTION)
	{
		resolve_expression(syntax_tree, previous_functions, expr->right, variables);
		// find the return value of the function ...
		find_function_and_resolve(syntax_tree, previous_functions, expr);
	}
	else if (expr->action == ARGUMENTS)
	{
		resolve_expression(syntax_tree, previous_functions, expr->right, variables);
		resolve_expression(syntax_tree, previous_functions, expr->left, variables);
	}
	else if (expr->action == RETURN)
	{
		// resolve the type returned and set the function (on top of previous_functions) return type
	}
}

void	resolve_indent_block(t_linked_list *syntax_tree, t_stack *previous_functions, t_linked_list *block, t_linked_list *variables)
{
	(void)syntax_tree;
	(void)block;
	(void)variables;
	(void)previous_functions;
}

void	resolve_function(t_linked_list *syntax_tree, t_stack *previous_functions)
{
	t_linked_list	*variables;
	int				i;
	t_linked_list	*function;

	function = ((t_linked_list*)previous_functions->elts[previous_functions->last - 1]);
	variables = new_list();
	add_function_args(function, variables);
	i = 0;
	while (i < function->len)
	{
		// if it's an indent block
		if (((t_sub_elt*)function->elts[i])->type == INDENT_BLOCK)
			resolve_indent_block(syntax_tree, previous_functions, ((t_sub_elt*)function->elts[i])->elt, variables);
		else
			resolve_expression(syntax_tree, previous_functions, ((t_sub_elt*)function->elts[i])->elt, variables);
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

int		parse_array_type(char *type)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (type[i])
		i++;
	i--;
	while (i >= 1 && type[i] == ']' && type[i - 1] == '[')
	{
		res += 100000;
		i -= 2;
	}
	type[i + 1] = '\0';
	if (ft_strcmp(type, "INTEGER") == 0)
		res += INTEGER;
	else if (ft_strcmp(type, "STRING") == 0)
		res += STRING;
	else if (ft_strcmp(type, "CHAR") == 0)
		res += CHAR;
	else if (ft_strcmp(type, "DOUBLE") == 0)
		res += DOUBLE;
	else if (ft_strcmp(type, "FLOAT") == 0)
		res += FLOATING;
	else if (ft_strcmp(type, "LONG") == 0)
		res += LONG;
	return (res);
}

t_node	*descr_to_node(char *descr)
{
	char	**tabs;
	t_node	*res;
	int		type;
	t_node	*tmp_node;

	// create a node with return type (tabs[0]), function name (tabs[1]) and arguments types (tab[2]),
	// just like a normal FUNCTION_DECL node
	tabs = split_on_char(descr, ft_strlen(descr), '\t');
	if (ft_strcmp(tabs[0], "VOID") == 0)
		type = 0;
	else if (ft_strcmp(tabs[0], "INTEGER") == 0)
		type = INTEGER;
	else if (ft_strcmp(tabs[0], "STRING") == 0)
		type = STRING;
	else if (ft_strcmp(tabs[0], "CHAR") == 0)
		type = CHAR;
	else if (ft_strcmp(tabs[0], "DOUBLE") == 0)
		type = DOUBLE;
	else if (ft_strcmp(tabs[0], "FLOAT") == 0)
		type = FLOATING;
	else if (ft_strcmp(tabs[0], "LONG") == 0)
		type = LONG;
	else
		type = parse_array_type(tabs[0]);
	res = new_node(FUNCTION_DECL, );
}

t_linked_list	*get_builtin_functions(void)
{
	char			*content;
	char			**functions;
	long			size;
	int				i;
	t_linked_list	*builtin_funcs;

	builtin_funcs = new_list();
	content = read_file_fast("builtin_functions.descr", &size);
	functions = split_on_char(content, size, '\n');
	i = 0;
	while (functions[i])
	{
		add_to_list(builtin_functions, descr_to_node(functions[i]));
		i++;
	}
	return (builtin_funcs);
}

void	resolve_types(t_linked_list *syntax_tree)
{
	int		i;
	t_stack	*tmp_functions;

	builtin_functions = get_builtin_functions();
	tmp_functions = new_stack();
	i = 0;
	while (i < syntax_tree->len)
	{
		stack_push(tmp_functions, ((t_linked_list*)((t_sub_elt*)syntax_tree->elts[i])->elt));
		resolve_function(syntax_tree, tmp_functions);
		stack_pop(tmp_functions);
		i++;
	}
}