

#include "Compose.h"

int		_int_double(double nb)
{
	return ((int)nb);
}

int		_int_str(t_string *str)
{
	int		res;
	int		i;
	char	sign;

	res = 0;
	i = 0;
	sign = 0;
	if (str->elts[0] == '-')
	{
		sign = 1;
		i = 1;
	}
	while (i < str->len)
	{
		res = res * 10 + (str->elts[i] - '0');
		i++;
	}
	if (sign)
		return (-res);
	return (res);
}