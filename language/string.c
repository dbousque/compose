

#include "Compose.h"

t_string	*_new_string(void)
{
	t_string	*ret;

	if (!(ret = (t_string*)_compose_malloc(sizeof(t_string))))
		_malloc_error();
	if (!(ret->elts = (char*)_compose_malloc(sizeof(char) * STRING_START_SIZE)))
		_malloc_error();
	ret->size = STRING_START_SIZE;
	ret->len = 0;
	return (ret);
}

t_string	*_new_string_chars_int(char *chars, int len)
{
	t_string	*ret;

	if (!(ret = (t_string*)_compose_malloc(sizeof(t_string))))
		_malloc_error();
	if (!(ret->elts = (char*)_compose_malloc(sizeof(char) * len)))
		_malloc_error();
	ret->size = len;
	ret->len = len;
	len--;
	while (len >= 0)
	{
		ret->elts[len] = chars[len];
		len--;
	}
	return (ret);
}

t_string	*_str_int(int nb)
{
	t_string	*res;

	if (!(res = (t_string*)_compose_malloc(sizeof(t_string))))
		_malloc_error();
	res->elts = _ft_ntoa_base(nb, "0123456789", 10, &(res->len));
	res->size = res->len;
	return (res);
}

t_string	*_str_long(long nb)
{
	t_string	*res;

	if (!(res = (t_string*)_compose_malloc(sizeof(t_string))))
		_malloc_error();
	res->elts = _ft_ntoa_base(nb, "0123456789", 10, &(res->len));
	res->size = res->len;
	return (res);
}

t_string	*_str_char(char nb)
{
	t_string	*res;

	if (!(res = (t_string*)_compose_malloc(sizeof(t_string))))
		_malloc_error();
	res->elts = _ft_ntoa_base(nb, "0123456789", 10, &(res->len));
	res->size = res->len;
	return (res);
}

t_string	*_str_str(t_string *str)
{
	return (str);
}

t_string	*_new_str_add_str_str(t_string *str1, t_string *str2)
{
	t_string	*res;
	int			i;

	if (!(res = (t_string*)_compose_malloc(sizeof(t_string))))
		_malloc_error();
	if (!(res->elts = (char*)_compose_malloc(sizeof(char) * (str1->len + str2->len))))
		_malloc_error();
	res->len = str1->len + str2->len;
	res->size = res->len;
	i = 0;
	while (i < str1->len)
	{
		res->elts[i] = str1->elts[i];
		i++;
	}
	i = 0;
	while (i < str2->len)
	{
		res->elts[str1->len + i] = str2->elts[i];
		i++;
	}
	return (res);
}

t_string	*_new_str_add_str_int(t_string *str, int n)
{
	t_string	*res;
	int			i;
	int			len;
	char		*tmp_str;

	if (!(res = (t_string*)_compose_malloc(sizeof(t_string))))
		_malloc_error();
	tmp_str = _ft_ntoa_base(n, "0123456789", 10, &len);
	if (!(res->elts = (char*)_compose_malloc(sizeof(char) * (str->len + len))))
		_malloc_error();
	res->len = str->len + len;
	res->size = res->len;
	i = 0;
	while (i < str->len)
	{
		res->elts[i] = str->elts[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		res->elts[str->len + i] = tmp_str[i];
		i++;
	}
	return (res);
}