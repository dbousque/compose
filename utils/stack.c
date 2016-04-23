

#include "utils.h"

t_stack	*new_stack(void)
{
	t_stack	*res;

	if (!(res = (t_stack*)malloc(sizeof(t_stack))))
		malloc_error();
	if (!(res->elts = (void**)malloc(sizeof(void*) * 2)))
		malloc_error();
	res->size = 2;
	res->last = 0;
}

void	double_stack_size(t_stack *stack)
{
	void	**new_elts;
	int		i;

	if (!(new_elts = (void**)malloc(sizeof(void*) * (stack->size * 2))))
		malloc_error();
	i = 0;
	while (i < stack->last)
	{
		new_elts[i] = stack->elts[i];
		i++;
	}
	free(stack->elts);
	stack->elts = new_elts;
	stack->size *= 2;
}

void	stack_push(t_stack *stack, void *elt)
{
	if (stack->last == stack->size)
		double_stack_size(stack);
	stack->elts[stack->last] = elt;
	stack->last++;
}

void	*stack_pop(t_stack *stack)
{
	if (stack->last <= 0)
		return (NULL);
	stack->last--;
	return (stack->elts[stack->last]);
}