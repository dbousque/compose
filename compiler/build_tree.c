

#include "build_tree.h"

void	print_details(void)
{
	ft_putstr("Please specify a file to compile.n\n");
}

void	compile_c_file(void)
{
	char	*command;

	command = "gcc -std=c99 a.out.c ../language/*.c ../garbage_collector/*.c";
	system(command);
}

void	compile_file(char *filename)
{
	t_linked_list	*syntax_tree;

	syntax_tree = get_abstract_syntax_tree(filename);
	print_syntax_tree(syntax_tree);
	resolve_types(syntax_tree);
	print_syntax_tree(syntax_tree);
	tree_to_c_code(syntax_tree);
	compile_c_file();
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		print_details();
	else
		compile_file(argv[1]);
	return (0);
}