

#include "build_tree.h"

void	get_indent_unit(char **lines, char *indent_char, int *nb_indent)
{
	int		i;
	int		x;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] == ' ' || lines[i][0] == '\t')
		{
			*indent_char = lines[i][0];
			x = 0;
			while (lines[i][x] == *indent_char)
				x++;
			*nb_indent = x;
			return ;
		}
		i++;
	}
	*indent_char = 0;
	*nb_indent = 0;
}

int		*get_indentation(char **lines, int *nb_indent_per_unit)
{
	int		*indent;
	int		i;
	int		x;
	char	indent_char;
	int		nb_indent;

	i = 0;
	while (lines[i])
		i++;
	if (!(indent = (int*)malloc(sizeof(int) * i)))
		malloc_error();
	get_indent_unit(lines, &indent_char, &nb_indent);
	*nb_indent_per_unit = nb_indent;
	i = 0;
	while (lines[i])
	{
		x = 0;
		while (lines[i][x] == indent_char)
			x++;
		if (x % nb_indent != 0)
		{
			ft_putstr("Indentation error.\n");
			exit(1);
		}
		indent[i] = x / nb_indent;
		i++;
	}
	return (indent);
}

t_linked_list	*get_abstract_syntax_tree(char *filename)
{
	t_linked_list	*functions;
	t_stack			*current_indent_blocks;
	t_linked_list	*tmp_indent_block;
	t_linked_list	*tmp_tmp_block;
	t_node			*tmp_node;
	int				*indentation;
	char			*source;
	long			file_size;
	char			**lines;
	int				i;
	int				tmp;
	int				nb_indent;
	char			last_was_new_indent;

	last_was_new_indent = 0;
	functions = new_list();
	current_indent_blocks = new_stack();
	source = read_file_fast(filename, &file_size);
	lines = split_on_char(source, file_size, '\n');
	indentation = get_indentation(lines, &nb_indent);
	i = 0;
	while (lines[i])
	{
		printf("%s\n", lines[i]);
		tmp_node = parse_line(lines[i] + (indentation[i] * nb_indent));
		if (functions->len == 0 && tmp_node->action != FUNCTION_DECL)
		{
			ft_putstr("Code outside of a function.\n");
			exit(1);
		}
		if (tmp_node->action == FUNCTION_DECL)
		{
			tmp_indent_block = new_list();
			add_to_list(functions, new_sub_elt(tmp_indent_block, INDENT_BLOCK));
			last_was_new_indent = 1;
		}
		else if (tmp_node->action == CONDITION || tmp_node->action == WHILE_LOOP || tmp_node->action == FOR_LOOP1 || tmp_node->action == FOR_LOOP2)
		{
			stack_push(current_indent_blocks, tmp_indent_block);
			tmp_tmp_block = new_list();
			add_to_list(tmp_indent_block, new_sub_elt(tmp_tmp_block, INDENT_BLOCK));
			tmp_indent_block = tmp_tmp_block;
			last_was_new_indent = 1;
		}
		else if (!last_was_new_indent && indentation[i] != indentation[i - 1])
		{
			if (indentation[i] > indentation[i - 1])
			{
				ft_putstr("Indentation error.\n");
				exit(1);
			}
			tmp = indentation[i];
			while (tmp < indentation[i - 1])
			{
				tmp_indent_block = stack_pop(current_indent_blocks);
				tmp++;
			}
			last_was_new_indent = 0;
		}
		else
			last_was_new_indent = 0;
		add_to_list(tmp_indent_block, new_sub_elt(tmp_node, INSTRUCTION));	
		print_tree(tmp_node);
		printf("\n");
		i++;
	}
	return (functions);
}

void	print_indent_block(t_linked_list *block, int indentation)
{
	int		i;

	i = 0;
	while (i < indentation)
	{
		printf("\t");
		i++;
	}
	printf("NEW INDENT BLOCK :\n");
	i = 0;
	while (i < block->len)
	{
		if (((t_sub_elt*)block->elts[i])->type == INSTRUCTION)
		{
			print_tree_indent(((t_sub_elt*)block->elts[i])->elt, indentation);
			printf("\n");
		}
		else if (((t_sub_elt*)block->elts[i])->type == INDENT_BLOCK)
			print_indent_block(((t_sub_elt*)block->elts[i])->elt, indentation + 1);
		else
			printf("UNKNOWN SUBBLOCK TYPE, should not happen.\n");
		i++;
	}
}

void	print_syntax_tree(t_linked_list *syntax_tree)
{
	int		i;

	printf("\n  ___\n\nPRINTING SYNTAX TREE :\n\n");
	i = 0;
	while (i < syntax_tree->len)
	{
		printf("NEW FUNCTION :\n\n");
		print_indent_block(((t_sub_elt*)syntax_tree->elts[i])->elt, 1);
		i++;
	}
}