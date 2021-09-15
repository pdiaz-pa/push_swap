#include "push_swap.h"

int ft_sort_two(t_stack *stack_a)
{
    printf("%s", "Hay 2 nodos para ordenar.\n");

    sa(stack_a);
    printf("%s", "OK\n");
    ft_stack_printer(stack_a);
    
    return(0);
}

int ft_sort_three(t_stack *stack_a)
{
    printf("%s", "Hay 3 nodos para ordenar.\n");
    if(stack_a->next->data > stack_a->next->next->data &&
        stack_a->next->next->data < stack_a->next->next->next->data &&
        stack_a->next->next->next->data > stack_a->next->data) // 2 1 3 V
    {
        printf("%s", "algo 1\n");
        sa(stack_a);
        return(0);
    }

    if((stack_a->next->data > stack_a->next->next->data) &&
        (stack_a->next->next->data > stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data < stack_a->next->data)) // 3 2 1 v
    {
        printf("%s", "algo 2\n");
        sa(stack_a);
        rra(stack_a);
        return(0);
    }

    if((stack_a->next->data > stack_a->next->next->data) &&
        (stack_a->next->next->data < stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data < stack_a->data)) // 3 1 2 V
    {
        printf("%s", "algo 3\n");
        ra(stack_a);
        return(0);
    }
    if((stack_a->next->data < stack_a->next->next->data) &&
        (stack_a->next->next->data > stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data > stack_a->next->data)) // 1 3 2 V
    {
        printf("%s", "algo 4\n");
        sa(stack_a);
        ra(stack_a);
        return(0);
    }
    if((stack_a->next->data < stack_a->next->next->data) &&
        (stack_a->next->next->data > stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data < stack_a->next->data)) // 2 3 1 V
    {
        printf("%s", "algo 5\n");
        rra(stack_a);
        return(0);    
    }
    return(0);
}

int ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
    printf("%s", "Hay 5 nodos para ordenar.\n");
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    ft_sort_three(stack_a);
    return(0);
}

int ft_sort_lot()
{
    printf("%s", "Hay muchos nodos para ordenar.\n");
    return(0);
}