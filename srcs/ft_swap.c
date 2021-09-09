#include "push_swap.h"

void    sa(t_stack *stack_a)
{
    int auxdata;

    auxdata = stack_a->data;
    stack_a->data = stack_a->next->data;
    stack_a->next->data = auxdata;
    printf("%s", "sa\n");
}

void    sb(t_stack *stack_b)
{
    int auxdata;

    auxdata = stack_b->data;
    stack_b->data = stack_b->next->data;
    stack_b->next->data = auxdata;
    printf("%s", "sb\n");
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);
    sb(stack_b);
    printf("%s", "ss");
}