

#include "Compose.h"

void	_malloc_error(void)
{
	char	*tmp_str;

	tmp_str = "Could not allocate memory\n";
	write(2, tmp_str, _ft_strlen(tmp_str));
	exit(1);
}