

#include "build_tree.h"

t_linked_list *builtin_functions;

void	write_start(int fd)
{
	char	*str;

	str = "\n\n#include \"../language/Compose.h\"\n\n";
	write(fd, str, ft_strlen(str));
}

void	write_end(int fd)
{
	char	*str;

	str = "int\t\tmain(int argc, char **argv)\n{\n\tt_list\t*args;\n\n\targs = _args_to_list(argc, argv);\n\t__main(args);\n\treturn (0);\n}";
	write(fd, str, ft_strlen(str));
}

char	*get_type_str(int type)
{
	if (type == 0)
		return (ft_strdup("void"));
	else if (type == INTEGER)
		return (ft_strdup("int"));
	else if (type == STRING)
		return (ft_strdup("t_string*"));
	else if (type == CHAR)
		return (ft_strdup("char"));
	else if (type == DOUBLE)
		return (ft_strdup("double"));
	else if (type == FLOATING)
		return (ft_strdup("float"));
	else if (type == LONG)
		return (ft_strdup("long"));
	else if (type >= LIST)
		return (ft_strdup("t_list*"));
	return (NULL);
}

void	write_proto_arg(int fd, t_node *elt)
{
	char	*tmp_str;

	if (!elt)
		return ;
	if (elt->left)
	{
		write_proto_arg(fd, elt->left);
		write(fd, ", ", 2);
	}
	tmp_str = get_type_str(elt->right->type);
	write(fd, tmp_str, ft_strlen(tmp_str));
	write(fd, " ___", 4);
	write(fd, elt->right->repr, ft_strlen(elt->right->repr));
}

void	write_function_prototype(int fd, t_linked_list *function)
{
	t_node	*prototype;
	char	*tmp_str;
	t_node	*tmp_node;

	prototype = ((t_node*)((t_sub_elt*)function->elts[0])->elt);
	tmp_str = get_type_str(prototype->type);
	write(fd, tmp_str, ft_strlen(tmp_str));
	write(fd, "\t__", 3);
	write(fd, prototype->left->repr, ft_strlen(prototype->left->repr));
	write(fd, "(", 1);
	tmp_node = prototype->right;
	write_proto_arg(fd, tmp_node);
	write(fd, ")\n{\n", 4);
}

void	write_n_indent(int fd, int n)
{
	while (n > 0)
	{
		write(fd, "\t", 1);
		n--;
	}
}

int		are_function_equal2(t_node *func1, t_node *func2)
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

t_node	*get_builtin_function(t_node *function_call)
{
	int		i;
	t_node	*tmp_func;

	i = 0;
	while (i < builtin_functions->len)
	{
		tmp_func = ((t_node*)builtin_functions->elts[i]);
		if (are_function_equal2(function_call, tmp_func))
			return (tmp_func);
		i++;
	}
	ft_putstr("PROBLEM, BUILTIN FUNCTION NOT FOUND\n");
	exit(1);
	return (NULL);
}

char	is_builtin_function2(t_node *function_call)
{
	int		i;
	t_node	*tmp_func;

	i = 0;
	while (i < builtin_functions->len)
	{
		tmp_func = ((t_node*)builtin_functions->elts[i]);
		if (are_function_equal2(function_call, tmp_func))
			return (1);
		i++;
	}
	return (0);
}

void	write_instruction(int fd, t_node *instr, int indentation)
{
	char	*tmp_str;
	t_node	*tmp_node;

	if (!instr)
		return ;
	write_n_indent(fd, indentation);
	if (instr->action == INTEGER || instr->action == LONG || instr->action == DOUBLE || instr->action == FLOATING || instr->action == CHAR)
		write(fd, instr->repr, ft_strlen(instr->repr));
	else if (instr->action == STRING)
	{
		tmp_str = ft_strjoin(ft_strjoin(ft_strjoin("_new_string_chars_int(", instr->repr), ", "), ft_itoa(ft_strlen(instr->repr) - 2));
		tmp_str = ft_strjoin(tmp_str, ")");
		write(fd, tmp_str, ft_strlen(tmp_str));
	}
	else if (instr->action == ASSIGNEMENT)
	{
		write(fd, "___", 3);
		write(fd, instr->left->repr, ft_strlen(instr->left->repr));
		write(fd, " = ", 3);
		write_instruction(fd, instr->right, 0);
	}
	else if (instr->action == PRIORITY)
	{
		write(fd, "(", 1);
		write_instruction(fd, instr->right, 0);
		write(fd, ")", 1);
	}
	else if (instr->action == RETURN)
	{
		tmp_str = "return ";
		write(fd, tmp_str, ft_strlen(tmp_str));
		write_instruction(fd, instr->right, 0);
	}
	else if (instr->action == ADD)
	{
		// string appending
		if (instr->left->type == STRING)
		{
			if (instr->right->type == STRING)
				tmp_str = "_new_str_add_str_str(";
			else if (instr->right->type == CHAR)
				tmp_str = "_new_str_add_str_char(";
			else if (instr->right->type == INTEGER)
				tmp_str = "_new_str_add_str_int(";
			else if (instr->right->type == LONG)
				tmp_str = "_new_str_add_str_long(";
			else if (instr->right->type == FLOATING)
				tmp_str = "_new_str_add_str_float(";
			else if (instr->right->type == DOUBLE)
				tmp_str = "_new_str_add_str_double(";
			write(fd, tmp_str, ft_strlen(tmp_str));
			write_instruction(fd, instr->left, 0);
			write(fd, ", ", 2);
			write_instruction(fd, instr->right, 0);
			write(fd, ")", 1);
		}
		else
		{
			write_instruction(fd, instr->left, 0);
			write(fd, " + ", 3);
			write_instruction(fd, instr->right, 0);
		}
	}
	else if (instr->action == MINUS)
	{
		write_instruction(fd, instr->left, 0);
		write(fd, " - ", 3);
		write_instruction(fd, instr->right, 0);
	}
	else if (instr->action == MULTIPL)
	{
		write_instruction(fd, instr->left, 0);
		write(fd, " * ", 3);
		write_instruction(fd, instr->right, 0);
	}
	else if (instr->action == DIVIDE)
	{
		write_instruction(fd, instr->left, 0);
		write(fd, " / ", 3);
		write_instruction(fd, instr->right, 0);
	}
	else if (instr->action == FUNCTION)
	{
		if (is_builtin_function2(instr))
		{
			tmp_node = get_builtin_function(instr);
			write(fd, tmp_node->repr, ft_strlen(tmp_node->repr));
		}
		else
		{
			write(fd, "__", 2);
			write(fd, instr->left->repr, ft_strlen(instr->left->repr));
		}
		write(fd, "(", 1);
		write_instruction(fd, instr->right, 0);
		write(fd, ")", 1);
	}
	else if (instr->action == ARGUMENTS)
	{
		if (instr->left)
		{
			write_instruction(fd, instr->left, 0);
			write(fd, ", ", 2);
		}
		write_instruction(fd, instr->right, 0);
	}
	else if (instr->action == VARIABLE)
	{
		write(fd, "___", 3);
		write(fd, instr->repr, ft_strlen(instr->repr));
	}
}

void	write_indent_start(int fd, t_node *instr, int indentation)
{
	t_node	*tmp_node;
	char	*tmp_str;
	char	*to_iter_name;

	if (instr->action == FOR_LOOP2)
	{
		// for now, right expression must be a list (or reducable to a list)
		if (instr->right->type < LIST)
		{
			ft_putstr("Can only iterate over lists.\n");
			exit(1);
		}
		// list to be iterated on
		write_n_indent(fd, indentation - 1);
		tmp_str = "____";
		write(fd, tmp_str, ft_strlen(tmp_str));
		to_iter_name = ft_strjoin("to_iter", ft_itoa(indentation));
		write(fd, to_iter_name, ft_strlen(to_iter_name));
		write(fd, " = ", 3);
		write_instruction(fd, instr->right, 0);
		write(fd, ";\n", 2);
		// for loop
		write_n_indent(fd, indentation - 1);
		tmp_str = "for (int ____i";
		write(fd, tmp_str, ft_strlen(tmp_str));
		write(fd, ft_itoa(indentation), ft_strlen(ft_itoa(indentation)));
		tmp_str = " = 0; ____i";
		write(fd, tmp_str, ft_strlen(tmp_str));
		write(fd, ft_itoa(indentation), ft_strlen(ft_itoa(indentation)));
		tmp_str = " < ____";
		write(fd, tmp_str, ft_strlen(tmp_str));
		write(fd, to_iter_name, ft_strlen(to_iter_name));
		tmp_str = "->len; ____i";
		write(fd, tmp_str, ft_strlen(tmp_str));
		write(fd, ft_itoa(indentation), ft_strlen(ft_itoa(indentation)));
		tmp_str = "++)\n";
		write(fd, tmp_str, ft_strlen(tmp_str));
		write_n_indent(fd, indentation - 1);
		write(fd, "{\n", 2);
		write_n_indent(fd, indentation);
		write(fd, "___", 3);
		write(fd, instr->left->repr, ft_strlen(instr->left->repr));
		tmp_str = " = (";
		write(fd, tmp_str, ft_strlen(tmp_str));
		tmp_str = get_type_str(instr->left->type);
		write(fd, tmp_str, ft_strlen(tmp_str));
		tmp_str = ")____";
		write(fd, tmp_str, ft_strlen(tmp_str));
		write(fd, to_iter_name, ft_strlen(to_iter_name));
		tmp_str = "->elts[____i";
		write(fd, tmp_str, ft_strlen(tmp_str));
		write(fd, ft_itoa(indentation), ft_strlen(ft_itoa(indentation)));
		tmp_str = "];\n";
		write(fd, tmp_str, ft_strlen(tmp_str));
	}
}

void	write_indent_block(int fd, t_linked_list *block, int indentation, int start)
{
	int		i;

	i = start;
	if (start == 0)
	{
		write_indent_start(fd, ((t_sub_elt*)block->elts[0])->elt, indentation);
		i = 1;
	}
	while (i < block->len)
	{
		if (((t_sub_elt*)block->elts[i])->type == INDENT_BLOCK)
			write_indent_block(fd, ((t_sub_elt*)block->elts[i])->elt, indentation + 1, 0);
		else
		{
			write_instruction(fd, (t_node*)((t_sub_elt*)block->elts[i])->elt, indentation);
			write(fd, ";\n", 2);
		}
		i++;
	}
	write_n_indent(fd, indentation - 1);
	write(fd, "}\n", 2);
}

void	write_declared_variables(int fd, t_linked_list *function, int indentation)
{
	int		i;
	char	*tmp_str;

	i = 0;
	while (i < function->len)
	{
		if (((t_sub_elt*)function->elts[i])->type == INSTRUCTION)
		{
			if (((t_node*)((t_sub_elt*)function->elts[i])->elt)->action == ASSIGNEMENT
					|| ((t_node*)((t_sub_elt*)function->elts[i])->elt)->action == FOR_LOOP2)
			{
				tmp_str = get_type_str(((t_node*)((t_sub_elt*)function->elts[i])->elt)->left->type);
				write(fd, "\t", 1);
				write(fd, tmp_str, ft_strlen(tmp_str));
				write(fd, "\t___", 4);
				tmp_str = ((t_node*)((t_sub_elt*)function->elts[i])->elt)->left->repr;
				write(fd, tmp_str, ft_strlen(tmp_str));
				write(fd, ";\n", 2);
			}
			if (((t_node*)((t_sub_elt*)function->elts[i])->elt)->action == FOR_LOOP2)
			{
				tmp_str = get_type_str(((t_node*)((t_sub_elt*)function->elts[i])->elt)->right->type);
				write(fd, "\t", 1);
				write(fd, tmp_str, ft_strlen(tmp_str));
				write(fd, "\t____", 5);
				tmp_str = "to_iter";
				write(fd, tmp_str, ft_strlen(tmp_str));
				tmp_str = ft_itoa(indentation);
				write(fd, tmp_str, ft_strlen(tmp_str));
				write(fd, ";\n", 2);
			}
		}
		else
			write_declared_variables(fd, ((t_sub_elt*)function->elts[i])->elt, indentation + 1);
		i++;
	}
}

void	write_function(int fd, t_linked_list *function)
{
	t_node			*tmp_node;
	t_linked_list	*variables;

	write_function_prototype(fd, function);
	write_declared_variables(fd, function, 1);
	write(fd, "\n", 1);
	write_indent_block(fd, function, 1, 1);
	write(fd, "\n", 1);
}

void	tree_to_c_code(t_linked_list *syntax_tree)
{
	int				i;
	t_linked_list	*tmp_func;
	int				fd;

	fd = open("a.out.c", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		file_opening_for_writing_error();
	write_start(fd);
	i = 0;
	while (i < syntax_tree->len)
	{
		tmp_func = ((t_linked_list*)((t_sub_elt*)syntax_tree->elts[i])->elt);
		write_function(fd, tmp_func);
		i++;
	}
	write_end(fd);
	close(fd);
}