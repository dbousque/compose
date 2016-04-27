

#include "build_tree.h"

void	print_details(void)
{
	ft_putstr("Please specify a file to compile.n\n");
}

void	compile_file(char *filename)
{
	t_linked_list	*syntax_tree;

	syntax_tree = get_abstract_syntax_tree(filename);
	print_syntax_tree(syntax_tree);
	resolve_types(syntax_tree);
	print_syntax_tree(syntax_tree);
	(void)syntax_tree;
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		print_details();
	else
		compile_file(argv[1]);
	return (0);
}