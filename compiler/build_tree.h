

#ifndef BUILD_TREE_H
# define BUILD_TREE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "tree.h"
# include "../utils/utils.h"

# define READING_BUF_SIZE 1024

t_node	*parse_line(char *line);
char	*read_file_fast(char *filename, long *file_size);
void	file_opening_error(void);
void	file_opening_for_writing_error(void);
void	file_reading_error(void);
void	malloc_error(void);

#endif