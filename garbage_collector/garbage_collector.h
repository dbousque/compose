

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <stdlib.h>

void	*_compose_malloc(size_t size);
void	_compose_free(void *ptr);

#endif