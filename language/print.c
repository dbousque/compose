

#include "Compose.h"

void	_print_int(int nb)
{
	char	*str;
	int		len;

	str = _ft_ntoa_base(nb, "0123456789", 10, &len);
	write(1, str, len);
	_compose_free(str);
	write(1, "\n", 1);
}

void	_print_long(long nb)
{
	char	*str;
	int		len;

	str = _ft_ntoa_base(nb, "0123456789", 10, &len);
	write(1, str, len);
	_compose_free(str);
	write(1, "\n", 1);
}

void	_print_char(char c)
{
	char	*str;
	int		len;

	str = _ft_ntoa_base(c, "0123456789", 10, &len);
	write(1, str, len);
	_compose_free(str);
	write(1, "\n", 1);
}

void	_print_str(t_string *str)
{
	write(1, str->elts, str->len);
	write(1, "\n", 1);
}