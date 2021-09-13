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
    stack_a = stack_a->next;
    printf("%s", "Hay 3 nodos para ordenar.\n");
    if(stack_a->data > stack_a->next->data && stack_a->next->data < stack_a->next->next->data && stack_a->next->next->data > stack_a->data) // 2 1 3 V
    {
        printf("%s", "algo 1\n");
        sa(stack_a);
        return(0);
    }

    if((stack_a->data > stack_a->next->data) && (stack_a->next->data > stack_a->next->next->data) && (stack_a->next->next->data < stack_a->data)) // 3 2 1 X
    {
        printf("%s", "algo 2\n");
        sa(stack_a);
        rra(stack_a);
        return(0);
    }

    if((stack_a->data > stack_a->next->data) && (stack_a->next->data < stack_a->next->next->data) && (stack_a->next->next->data < stack_a->data)) // 3 1 2 X
    {
        printf("%s", "algo 3\n");
        ra(stack_a);
        return(0);
    }
    if((stack_a->data < stack_a->next->data) && (stack_a->next->data > stack_a->next->next->data) && (stack_a->next->next->data > stack_a->data)) // 1 3 2 X
    {
        printf("%s", "algo 4\n");
        sa(stack_a);
        ra(stack_a);
        return(0);
    }
    if((stack_a->data < stack_a->next->data) && (stack_a->next->data > stack_a->next->next->data) && (stack_a->next->next->data < stack_a->data)) // 2 3 1 X
    {
        printf("%s", "algo 5\n");
        rra(stack_a);
        return(0);    
    }


    return(0);
}

int ft_sort_five()
{
    printf("%s", "Hay 5 nodos para ordenar.\n");
    return(0);
}

int ft_sort_lot()
{
    printf("%s", "Hay muchos nodos para ordenar.\n");
    return(0);
}