

#include "../language/Compose.h"

int	__second_func(int ___lol)
{
	int	___a;

	___a = __second_func(12);
	return 24;
}

int	__first_function(int ___a, int ___i)
{
	int	___b1;
	float	___b2;
	long	___b3;
	long	___b8;
	double	___b4;
	long	___b7;
	t_string*	___b5;

	___b1 = 12;
	___b2 = 2.0;
	___b3 = 12;
	___b8 = ((3 + 5) * 4 - 1) * 7;
	___b4 = 2.0;
	___b7 = ___b3;
	___b5 = _str_long(___b3);
	_print_str(___b5);
	return _int_double(___i + ___a + ___b4);
}

void	__main(t_list* ___args)
{
	t_string*	___elt;
	t_list*	____to_iter2;

	____to_iter2 = ___args;
	for (int ____i2 = 0; ____i2 < ____to_iter2->len; ____i2++)
	{
		___elt = (t_string*)____to_iter2->elts[____i2];
		_print_str(___elt);
		_print_int(__first_function(2, 5));
	}
	_print_str(_new_string_chars_int("ok", 2));
}

int		main(int argc, char **argv)
{
	t_list	*args;

	args = _args_to_list(argc, argv);
	__main(args);
	return (0);
}