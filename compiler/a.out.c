

#include "../language/Compose.h"

t_string*	__my_func(t_string* ___string, int ___to_add)
{

	return _new_str_add_str_str(_new_str_add_str_int(_new_str_add_str_str(___string, _new_string_chars_int(" : to_add==", 11)), ___to_add), _new_string_chars_int(".", 1));
}

void	__main(t_list* ___args)
{
	t_string*	___elt;
	t_list*	____to_iter2;

	____to_iter2 = ___args;
	for (int ____i2 = 0; ____i2 < ____to_iter2->len; ____i2++)
	{
		___elt = (t_string*)____to_iter2->elts[____i2];
		_print_str(__my_func(_new_string_chars_int("line_start", 10), _int_str(___elt)));
	}
}

int		main(int argc, char **argv)
{
	t_list	*args;

	args = _args_to_list(argc, argv);
	__main(args);
	return (0);
}