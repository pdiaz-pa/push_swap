#include "push_swap.h"

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int auxdata;

    size = ft_size_stack(stack_b);
    if (size < 2)
        return ;
    auxdata = stack_b->data;
    pop(stack_b);
    ft_push_first(stack_a, auxdata);
    printf("%s", "pa\n");
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int auxdata;

    size = ft_size_stack(stack_a);
    if (size < 2)
        return ;
    pop(stack_a);
    ft_push_first(stack_a, auxdata);
    printf("%s", "pb\n");
}