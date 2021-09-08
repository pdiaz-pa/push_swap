#include "push_swap.h"

int ft_space_checker(char *argv)
{
    int i;
    i = 0;
    while (argv[i] != '\0')
    {
        if(argv[i] == ' ')
            return(1);
        i++;
    }
    return(0);
}

int ft_num_counter(char *argv)
{
    int i;
    int j;

    j = 0;
    i = 0;
    
    while (argv[i] != '\0')
    {
        if(argv[i] == ' ')
            j++;
        i++;
    }
    return(j);
}

int ft_size_selector(t_stack *stack)
{
    int nbr_nodes;

    nbr_nodes = 0;

    stack = stack->next; // para que no se imprima el primer 0 (ni idea de si está bien esto, debería estarlo, ya que cuando haces un push, lo hace por debajo del 0).
    while(stack->next != NULL) // imprime cada nodo 
    {
        nbr_nodes++;
        stack = stack->next;
    }
    return (nbr_nodes);
}

long long *ft_positivizer(long long *nums)
{
    int i;
    int min;
    
    i = 1;
    min = 0;

    while(nums[i] != '\0')
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }

        i++;
    }
    i = 1;
    while(nums[i] != '\0')
    {
        nums[i] = nums[i] + (min * -1);
        printf("%lld: positivizer working!!!\n", nums[i]);
        i++;
    }
    return(nums);
}