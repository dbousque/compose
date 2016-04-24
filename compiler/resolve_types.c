

#include "build_tree.h"

void	add_function_args(t_linked_list *function, t_linked_list *variables)
{
	t_node			*tmp_node;

	// prototype, get the arguments
	tmp_node = ((t_node*)((t_sub_elt*)function->elts[0])->elt);
	tmp_node = tmp_node->right;
	while (tmp_node)
	{
		if (tmp_node->action == VARIABLE)
			add_to_list(variables, tmp_node);
		else
			add_to_list(variables, tmp_node->right);
		tmp_node = tmp_node->left;
	}
}

void	resolve_indent_block(t_linked_list *block, t_linked_list *variables, t_linked_list *function)
{
	int		i;

	(void)i;
	(void)block;
	(void)variables;
	(void)function;
}

void	resolve_expr_type(t_node *expr, t_linked_list *variables)
{
	(void)variables;
	(void)expr;
}

void	resolve_function(t_linked_list *function)
{
	t_node			*tmp_node;
	int				i;
	t_linked_list	*variables;

	variables = new_list();
	add_function_args(function, variables);
	i = 0;
	while (i < variables->len)
	{
		print_tree(variables->elts[i]);
		printf("\n");
		i++;
	}
	i = 1;
	while (i < function->len)
	{
		if (((t_sub_elt*)function->elts[i])->type == INDENT_BLOCK)
			resolve_indent_block(((t_sub_elt*)function->elts[i])->elt, variables, function);
		else if (((t_sub_elt*)function->elts[i])->type == INSTRUCTION)
		{
			tmp_node = ((t_node*)((t_sub_elt*)function->elts[i])->elt);
			if (tmp_node->action == ASSIGNEMENT)
			{
				resolve_expr_type(tmp_node->right, variables);
				if (!tmp_node->left->type || tmp_node->left->type == tmp_node->right->type)
					tmp_node->left->type = tmp_node->right->type;
				else
				{
					printf("Types don't match and can't be casted without losing precision.\n");
					exit(1);
				}
				add_to_list(variables, tmp_node->left);
			}
			else if (tmp_node->action == RETURN)
			{
				resolve_expr_type(tmp_node->right, variables);
				// find the type returned and set this type to the function prototype
				if (((t_node*)((t_sub_elt*)function->elts[0])->elt)->type != 0 && tmp_node->right->type != 0
							&& tmp_node->right->type != ((t_node*)((t_sub_elt*)function->elts[0])->elt)->type)
				{
					// type conflict
					printf("Function return value type conflict.\n");
					exit(1);
				}
				((t_node*)((t_sub_elt*)function->elts[0])->elt)->type = tmp_node->right->type;
			}
		}
		else
		{
			printf("UNKNOWN SUB_ELT TYPE!!!\n");
			exit(1);
		}
		i++;
	}
	printf("PROTOTYPE : \n");
	i = 0;
	while (i < variables->len)
	{
		print_tree(variables->elts[i]);
		printf("\n");
		i++;
	}
	printf("SPLIT");
	//print_tree(prototype);
	printf("\n");
}

void	resolve_types(t_linked_list *syntax_tree)
{
	int		i;

	i = 0;
	while (i < syntax_tree->len)
	{
		resolve_function(((t_linked_list*)((t_sub_elt*)syntax_tree->elts[i])->elt));
		i++;
	}
}