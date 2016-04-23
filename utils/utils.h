

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_linked_list
{
	void		**elts;
	int			len;
	int			size;
}				t_linked_list;

typedef struct	s_stack
{
	void		**elts;
	int			last;
	int			size;
}				t_stack;

t_linked_list	*new_list(void);
void			add_to_list(t_linked_list *list, void *elt);
t_stack		*new_stack(void);
void		stack_push(t_stack *stack, void *elt);
void		*stack_pop(t_stack *stack);
char		*ft_ntoa_base(long long n, char *base);
char		*ft_itoa(long n);
long		ft_strlen(char *str);
int			pos_int_str_len(int n);
long		ft_atoi_with_size(char *str, long len);
void		ft_putstr(char *str);
char		**split_on_char(char *string, long string_len, char to_split);
char		char_in_string2(char c, char *str);
char		is_number(char c);
int			ft_strcmp(char *str1, char *str2);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *str1, char *str2);

#endif