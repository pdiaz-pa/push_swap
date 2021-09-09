#include "push_swap.h"

int ft_sort_two(t_stack *stack_a)
{
    printf("%s", "Hay 2 nodos para ordenar.\n");

    sa(stack_a);
    printf("%s", "OK\n");
    ft_stack_printer(stack_a);
    
    return(0);
}

int ft_sort_three()
{
    printf("%s", "Hay 3 nodos para ordenar.\n");
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