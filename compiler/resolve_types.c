

#include "build_tree.h"

t_linked_list *builtin_functions;

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

int		typeof_var_in_list(char *var_name, t_linked_list *variables)
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
	if (operation == ADD && type1 == STRING)
		return (STRING);
	return (0);
}

int		are_function_equal(t_node *func1, t_node *func2)
{
	t_node	*tmp1;
	t_node	*tmp2;
	char	ok;

	if (ft_strcmp(func1->left->repr, func2->left->repr) == 0)
	{
		// test if the arguments types match
		tmp1 = func1->right;
		tmp2 = func2->right;
		ok = 1;
		while (ok && tmp1 && tmp2)
		{
			if (tmp1->right->type != tmp2->right->type)
				ok = 0;
			tmp1 = tmp1->left;
			tmp2 = tmp2->left;
		}
		// if arguments match
		if (ok && !tmp1 && !tmp2)
			return (1);
	}
	return (0);
}

int		get_builtin_type(t_node *function_call)
{
	int		i;
	t_node	*tmp_func;

	i = 0;
	while (i < builtin_functions->len)
	{
		tmp_func = ((t_node*)builtin_functions->elts[i]);
		if (are_function_equal(function_call, tmp_func))
			return (tmp_func->type);
		i++;
	}
	ft_putstr("SHOULD NOT HAPPEN, BUILTIN FUNCTION NOT FOUND\n");
	return (0);
}

char	is_builtin_function(t_node *function_call)
{
	int		i;
	t_node	*tmp_func;

	i = 0;
	while (i < builtin_functions->len)
	{
		tmp_func = ((t_node*)builtin_functions->elts[i]);
		if (are_function_equal(function_call, tmp_func))
			return (1);
		i++;
	}
	return (0);
}

t_linked_list	*get_function_in_syntax_tree(t_linked_list *syntax_tree, t_node *function_call)
{
	// return a pointer to the function 
	int		i;
	t_node	*func_decl;

	i = 0;
	while (i < syntax_tree->len)
	{
		func_decl = ((t_node*)((t_sub_elt*)((t_linked_list*)((t_sub_elt*)syntax_tree->elts[i])->elt)->elts[0])->elt);
		if (are_function_equal(func_decl, function_call))
			return (((t_sub_elt*)(t_linked_list*)syntax_tree->elts[i])->elt);
		i++;
	}
	return (NULL);
}

char	function_twice_in_previous_functions(t_stack *previous_functions, t_node *function_call)
{
	int		i;
	t_node	*tmp_func;
	char	nb;

	nb = 0;
	i = 0;
	while (i < previous_functions->last)
	{
		tmp_func = ((t_node*)((t_sub_elt*)((t_linked_list*)previous_functions->elts[i])->elts[0])->elt);
		if (are_function_equal(function_call, tmp_func))
		{
			nb++;
			if (nb >= 2)
				return (1);
		}
		i++;
	}
	return (0);
}

void	find_function_and_resolve(t_linked_list *syntax_tree, t_stack *previous_functions, t_node *function_call)
{
	t_linked_list	*func;

	// set the expression type to be the function return type
	if (is_builtin_function(function_call))
	{
		// just look the return type up
		function_call->type = get_builtin_type(function_call);
	}
	else
	{
		// look for this function in the syntax tree, and resolve the return type of it.
		// If stuck in a loop (function calls itself, we can see that if the function is already in the previous_functions),
		// then ignore the looping function call, and resolve all the rest. If the type of the return values can't be determined
		// after that, then exit and ask the user to specify the return type of the function
		func = get_function_in_syntax_tree(syntax_tree, function_call);
		if (func)
		{
			// if we already know the return type, no need to search for it
			if (((t_node*)((t_sub_elt*)func->elts[0])->elt)->type)
			{
				function_call->type = ((t_node*)((t_sub_elt*)func->elts[0])->elt)->type;
				return ;
			}
			if (function_twice_in_previous_functions(previous_functions, function_call))
			{
				//ft_putstr("Endless recursion.\n");
				//exit(1);
				return ;
			}
			stack_push(previous_functions, func);
			resolve_function(syntax_tree, previous_functions);
			stack_pop(previous_functions);
			if (!((t_node*)((t_sub_elt*)func->elts[0])->elt)->type)
			{
				ft_putstr("Could not resolve the return type of the function. You program is likely to contain an error, otherwise just specify the return type of the function.\n");
				exit(1);
			}
			function_call->type = ((t_node*)((t_sub_elt*)func->elts[0])->elt)->type;
		}
		else
		{
			printf("Undefined reference to a function : %s\n", function_call->left->repr);
			exit(1);
		}
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
	else if (expr->action == VARIABLE)
	{
		// find the variable referenced and assign its type to the node, if not found, reference to nothing, error
		if (var_in_list(expr->repr, variables))
			expr->type = typeof_var_in_list(expr->repr, variables);
		else
		{
			ft_putstr("Variable referenced before assignement.\n");
			exit(1);
		}
	}
	else if (expr->action == FOR_LOOP2)
	{
		resolve_expression(syntax_tree, previous_functions, expr->right, variables);
		if (!expr->left->type || expr->left->type == expr->right->type - LIST)
			expr->left->type = expr->right->type - LIST;
		else
		{
			ft_putstr("Trying to assign from incompatible types.\n");
			exit(1);
		}
		if (!var_in_list(expr->left->repr, variables))
			add_to_list(variables, expr->left);
	}
	else if (expr->action == RETURN)
	{
		// resolve the type returned and set the function (on top of previous_functions) return type
		resolve_expression(syntax_tree, previous_functions, expr->right, variables);
		expr->type = expr->right->type;
		if (((t_node*)((t_sub_elt*)((t_linked_list*)previous_functions->elts[previous_functions->last - 1])->elts[0])->elt)->type
			&& ((t_node*)((t_sub_elt*)((t_linked_list*)previous_functions->elts[previous_functions->last - 1])->elts[0])->elt)->type != expr->type)
		{
			ft_putstr("Function return type conflict.\n");
			exit(1);
		}
		((t_node*)((t_sub_elt*)((t_linked_list*)previous_functions->elts[previous_functions->last - 1])->elts[0])->elt)->type = expr->type;
	}
}

void	resolve_indent_block(t_linked_list *syntax_tree, t_stack *previous_functions, t_linked_list *block, t_linked_list *variables)
{
	int		i;

	i = 0;
	// just do the same as in reolve function :
	while (i < block->len)
	{
		// if it's an indent block
		if (((t_sub_elt*)block->elts[i])->type == INDENT_BLOCK)
			resolve_indent_block(syntax_tree, previous_functions, ((t_sub_elt*)block->elts[i])->elt, variables);
		else
			resolve_expression(syntax_tree, previous_functions, ((t_sub_elt*)block->elts[i])->elt, variables);
		i++;
	}
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

int		parse_type(char *type)
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
		res += LIST;
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
	char	**args_type;
	t_node	*res;
	int		ret_type;
	t_node	*tmp_node;
	t_node	*tmp_node2;
	int		i;

	// create a node with return type (tabs[0]), function name (tabs[1]) and arguments types (tab[2]),
	// just like a normal FUNCTION_DECL node
	tabs = split_on_char(descr, ft_strlen(descr), '\t');
	ret_type = parse_type(tabs[0]);
	args_type = split_on_char(tabs[2], ft_strlen(tabs[2]), ',');
	if (ft_strcmp(args_type[0], "VOID") == 0)
		tmp_node = NULL;
	else
	{
		tmp_node = NULL;
		i = 0;
		while (args_type[i])
		{
			tmp_node2 = new_node(FUNCTION_ARGS, tmp_node, new_node(VARIABLE, NULL, NULL, "", parse_type(args_type[i])), "", 0);
			tmp_node = tmp_node2;
			i++;
		}
	}
	res = new_node(FUNCTION_DECL, new_node(0, NULL, NULL, tabs[1], 0), tmp_node, tabs[3], ret_type);
	return (res);
}

void	get_builtin_functions(void)
{
	char			*content;
	char			**functions;
	long			size;
	int				i;

	builtin_functions = new_list();
	content = read_file_fast("builtin_functions.descr", &size);
	functions = split_on_char(content, size, '\n');
	i = 0;
	while (functions[i])
	{
		add_to_list(builtin_functions, descr_to_node(functions[i]));
		i++;
	}
}

void	resolve_types(t_linked_list *syntax_tree)
{
	int		i;
	t_stack	*tmp_functions;

	printf("CALLED\n");
	fflush(stdout);
	get_builtin_functions();
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