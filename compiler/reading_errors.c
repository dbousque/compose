

#include "build_tree.h"

void	malloc_error(void)
{
	ft_putstr("Could not allocate memory.\n");
	exit(1);
}

void	file_opening_error(void)
{
	ft_putstr("Could not open file.\n");
}

void	file_opening_for_writing_error(void)
{
	ft_putstr("Could not open file for writing.\n");
}

void	file_reading_error(void)
{
	ft_putstr("An error occured while reading file.\n");
}