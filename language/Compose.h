

#ifndef COMPOSE_H
# define COMPOSE_H

# include <unistd.h>

# include "../garbage_collector/garbage_collector.h"

typedef struct	s_string
{
	int			len;
	int			size;
	char		*elts;
}				t_string;

typedef struct	s_list_int
{
	int			len;
	int			size;
	int			*elts;
}				t_list_int;

typedef struct	s_list
{
	int			len;
	int			size;
	void		**elts;
}				t_list;

# define STRING_START_SIZE 12
# define LIST_START_SIZE 12

/* UTILS */
size_t		_ft_strlen(char *str);
char		*_ft_ntoa_base(long long n, char *base, int base_length, int *len);

/* ERRORS */
void		_malloc_error(void);

/* STRING */
t_string	*_new_string(void);
t_string	*_new_string_chars_int(char *chars, int len);
t_string	*_str_int(int nb);
t_string	*_str_long(long nb);
t_string	*_str_char(char nb);
t_string	*_str_str(t_string *str);
t_string	*_new_str_add_str_str(t_string *str1, t_string *str2);
t_string	*_new_str_add_str_int(t_string *str, int n);

/* LIST */
t_list		*_new_list(void);
t_list		*_new_list_of_size(int size);
t_list_int	*_new_list_int(void);
t_list_int	*_new_list_of_size_int(int size);
void		_double_list_size(t_list *list);
void		_double_list_size_int(t_list_int *list);
void		_add_to_list(t_list *list, void *elt);
void		_add_to_list_int(t_list_int *list, int nb);

/* PRINT */
void		_print_int(int nb);
void		_print_long(long nb);
void		_print_char(char c);
void		_print_str(t_string *str);

/* INT */
int			_int_double(double nb);
int			_int_str(t_string *str);

/* ARGS_TO_LIST */
t_list		*_args_to_list(int argc, char **argv);

#endif