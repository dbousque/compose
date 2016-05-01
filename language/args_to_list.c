

#include "Compose.h"

t_list	*_args_to_list(int argc, char **argv)
{
	t_list	*args;
	int		i;

	args = _new_list_of_size(argc - 1);
	i = 1;
	while (i < argc)
	{
		_add_to_list(args, _new_string_chars_int(argv[i], _ft_strlen(argv[i])));
		i++;
	}
	return (args);
}