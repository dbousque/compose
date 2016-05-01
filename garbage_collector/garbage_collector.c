

#include "garbage_collector.h"

void	*_compose_malloc(size_t size)
{
	return (malloc(size));
}

void	_compose_free(void *ptr)
{
	free(ptr);
}