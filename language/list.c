

#include "Compose.h"

t_list	*_new_list(void)
{
	t_list	*res;

	if (!(res = (t_list*)_compose_malloc(sizeof(t_list))))
		_malloc_error();
	if (!(res->elts = (void**)_compose_malloc(sizeof(void*) * LIST_START_SIZE)))
		_malloc_error();
	res->size = LIST_START_SIZE;
	res->len = 0;
	return (res);
}

t_list	*_new_list_of_size(int size)
{
	t_list	*res;

	if (!(res = (t_list*)_compose_malloc(sizeof(t_list))))
		_malloc_error();
	if (!(res->elts = (void**)_compose_malloc(sizeof(void*) * size)))
		_malloc_error();
	res->size = size;
	res->len = 0;
	return (res);
}

t_list_int	*_new_list_int(void)
{
	t_list_int	*res;

	if (!(res = (t_list_int*)_compose_malloc(sizeof(t_list_int))))
		_malloc_error();
	if (!(res->elts = (int*)_compose_malloc(sizeof(int) * LIST_START_SIZE)))
		_malloc_error();
	res->size = LIST_START_SIZE;
	res->len = 0;
	return (res);
}

t_list_int	*_new_list_of_size_int(int size)
{
	t_list_int	*res;

	if (!(res = (t_list_int*)_compose_malloc(sizeof(t_list_int))))
		_malloc_error();
	if (!(res->elts = (int*)_compose_malloc(sizeof(int) * size)))
		_malloc_error();
	res->size = size;
	res->len = 0;
	return (res);
}

void	_double_list_size(t_list *list)
{
	void	**new_elts;
	int		i;

	if (!(new_elts = (void**)_compose_malloc(sizeof(void*) * list->size * 2)))
		_malloc_error();
	i = 0;
	while (i < list->len)
	{
		new_elts[i] = list->elts[i];
		i++;
	}
	_compose_free(list->elts);
	list->elts = new_elts;
}

void	_double_list_size_int(t_list_int *list)
{
	int		*new_elts;
	int		i;

	if (!(new_elts = (int*)_compose_malloc(sizeof(int) * list->size * 2)))
		_malloc_error();
	i = 0;
	while (i < list->len)
	{
		new_elts[i] = list->elts[i];
		i++;
	}
	_compose_free(list->elts);
	list->elts = new_elts;
}

void	_add_to_list(t_list *list, void *elt)
{
	if (list->len == list->size)
		_double_list_size(list);
	list->elts[list->len] = elt;
	list->len++;
}

void	_add_to_list_int(t_list_int *list, int nb)
{
	if (list->len == list->size)
		_double_list_size_int(list);
	list->elts[list->len] = nb;
	list->len++;
}