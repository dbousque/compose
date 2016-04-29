

#include "build_tree.h"

void	write_start(int fd)
{
	char	*str;

	str = "\n\n#include \"../language/language.h\"\n\n";
	write(fd, str, ft_strlen(str));
}

void	write_end(int fd)
{
	char	*str;

	str = "\n\nint\t\tmain(int argc, char **argv)\n{\n\tt_list\t*args;\n\n\targs = _args_to_list(argc, argv);\n\t__main(args);\n\treturn (0);\n}";
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
	while (tmp_node)
	{
		tmp_str = get_type_str(tmp_node->right->type);
		write(fd, tmp_str, ft_strlen(tmp_str));
		write(fd, " ", 1);
		write(fd, tmp_node->right->repr, ft_strlen(tmp_node->right->repr));
		if (tmp_node->left)
			write(fd, ", ", 2);
		tmp_node = tmp_node->left;
	}
	write(fd, ")\n{\n", 4);
}



void	write_indent_block(int fd, t_linked_list *block, int indentation, int start)
{
	int		i;

	if (start == 0)
	i = start;
	while (i < block->len)
	{
		if (((t_sub_elt*)block->elts[i])->type == INDENT_BLOCK)
			write_indent_block(fd, ((t_sub_elt*)block->elts[i])->elt, indentation + 1, 0);
		else
			write_instruction(fd, (t_node*)((t_sub_elt*)block->elts[i])->elt, indentation);
		i++;
	}
}

void	write_function(int fd, t_linked_list *function)
{
	t_node	*tmp_node;

	write_function_prototype(fd, function);
	write_indent_block(fd, function, 1, 1);
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
}