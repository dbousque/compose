

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

void	write_function(int fd, t_linked_list *function)
{
	t_node	*prototype;

	prototype = tmp_node = ((t_node*)((t_sub_elt*)function->elts[0])->elt);
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