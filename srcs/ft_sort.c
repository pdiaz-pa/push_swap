#include "push_swap.h"

int ft_sort_two(t_stack *stack_a)
{
    //printf("%s", "Hay 2 nodos para ordenar.\n");
    if (stack_a->next->data > stack_a->next->next->data)
    {
        sa(stack_a);
        //printf("%s", "OK\n");
    }

    //ft_stack_printer(stack_a);
    
    return(0);
}

int ft_sort_three(t_stack *stack_a)
{
    //printf("%s", "Hay 3 nodos para ordenar.\n");
    if(stack_a->next->data > stack_a->next->next->data &&
        stack_a->next->next->data < stack_a->next->next->next->data &&
        stack_a->next->next->next->data > stack_a->next->data) // 2 1 3 V
    {
        //printf("%s", "algo 1\n");
        sa(stack_a);
        return(0);
    }

    if((stack_a->next->data > stack_a->next->next->data) &&
        (stack_a->next->next->data > stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data < stack_a->next->data)) // 3 2 1 v
    {
        //printf("%s", "algo 2\n");
        sa(stack_a);
        rra(stack_a);
        return(0);
    }

    if((stack_a->next->data > stack_a->next->next->data) &&
        (stack_a->next->next->data < stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data < stack_a->data)) // 3 1 2 V
    {
        //printf("%s", "algo 3\n");
        ra(stack_a);
        return(0);
    }
    if((stack_a->next->data < stack_a->next->next->data) &&
        (stack_a->next->next->data > stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data > stack_a->next->data)) // 1 3 2 V
    {
        //printf("%s", "algo 4\n");
        sa(stack_a);
        ra(stack_a);
        return(0);
    }
    if((stack_a->next->data < stack_a->next->next->data) &&
        (stack_a->next->next->data > stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data < stack_a->next->data)) // 2 3 1 V
    {
        //printf("%s", "algo 5\n");
        rra(stack_a);
        return(0);    
    }
    return(0);
}

int ft_max_finder(t_stack *stack_a)
{
    int max;

    max = 0;
    stack_a = stack_a->next;
    while(stack_a != NULL)
    {
        if (stack_a->data > max)
            max = stack_a->data;
        stack_a = stack_a->next;
    }
    //printf("%d MAX\n", max);
    return(max);
}

int ft_min_finder(t_stack *stack_a, int max)
{
    int min;

    min = max;
    stack_a = stack_a->next;
    while(stack_a != NULL)
    {
        if (stack_a->data < min)
            min = stack_a->data;
        stack_a = stack_a->next;
    }
    //printf("%d MIN\n", min);
    return(min);
}

int ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
    //printf("%s", "Hay 5 nodos para ordenar.\n");
    int max;
    int min;
    
    max = ft_max_finder(stack_a);
    min = ft_min_finder(stack_a, max);
    if (max == stack_a->next->next->next->next->next->data)
        rra(stack_a);

    while (stack_a->next->data != max)
        ra(stack_a);
    pb(stack_a, stack_b);
    if (min == stack_a->next->next->next->next->data)
        rra(stack_a);
    while (stack_a->next->data != min)
        ra(stack_a);
    pb(stack_a, stack_b);
    ft_sort_three(stack_a);
    ft_sort_two(stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    ra(stack_a);


    return(0);
}

int ft_sort_lot()
{
    printf("%s", "Hay muchos nodos para ordenar.\n");
    return(0);
}