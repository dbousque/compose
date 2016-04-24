

#include "builtin_functions.h"

t_linked_list	*get_builtin_functions_name(void)
{
	t_linked_list	*functions;
	char			*content;
	char			**lines;
	long			size;
	int				i;

	functions = new_list();
	content = read_file_fast("builtin_functions.descr", &size);
	lines = split_on_char(content, size, '\n');
	i = 0;
	while (lines[i])
	{
		add_to_list(functions, lines[i]);
		i++;
	}
	free(lines);
	free(content);
	return (functions);
}