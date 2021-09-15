#include "push_swap.h"

void    sa(t_stack *stack_a)
{
    int auxdata;
    int size;

	size = ft_size_selector(stack_a);
	if (size < 2)
		return ;
	auxdata = stack_a->next->next->data;
	stack_a->next->next->data = stack_a->next->data;
	stack_a->next->data = auxdata;
    printf("%s", "sa\n");
}

void    sb(t_stack *stack_b)
{
    int auxdata;
    int size;

	size = ft_size_selector(stack_b);
	if (size < 2)
		return ;
	auxdata = stack_b->next->next->data;
	stack_b->next->next->data = stack_b->next->data;
	stack_b->next->data = auxdata;
    printf("%s", "sb\n");
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    printf("%s", "ss");
}