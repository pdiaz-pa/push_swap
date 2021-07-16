/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:16 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/07/14 14:36:00 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(char *str)
{
    printf("%s", "Error\n");
    printf("%s\n", str);
}

void ft_make_list(t_stack *head, int *nums, int array_size)
{
    int i;
    i = 0;
    printf("%d uahu \n", array_size);
    while(i < array_size)
    {
        push(head, nums[i]);
        i++;
    }
    free(nums);
}
void ft_stack_printer(t_stack *stack)
{
    stack = stack->next; // para que no se imprima el primer 0 (ni idea de si está bien esto, debería estarlo, ya que cuando haces un push, lo hace por debajo del 0).
    while(stack->next != NULL) // imprime cada nodo 
    {
        printf("%d->", stack->data);
        stack = stack->next;
    }
    printf("NULL\n");
}
int ft_args_array(int argc, char **argv, t_stack *a)
{
    int i;
    int *nums;
    int j;
    i = 1;
    j = 0;
    
    nums = (int *)malloc(sizeof(int) * (argc + 1));
    
    while (i < argc)
    {  
        while(argv[i][j] != '\0')
        {
            if (ft_isdigit(argv[i][j]) == 0)
            {
                ft_error("Los argumentos han de ser númericos.\n");
                return(-1);
            }
            j++;
        }
        nums[i] = ft_atoi(argv[i]); 
        printf("%d data \n", nums[i]);
        j = 0;
        i++;
        
    }
    

    nums = reverse_array(nums, (argc));
    nums[i++] = '\0';
    if (ft_is_sort(nums) == -1)
    {
        ft_error("Ya están ordenados.\n");
        return(-2);
    }

    ft_make_list(a, nums, i); //crea nodos por cada uno de los elementos del array que hemos creado y los enlaza para crear una lista enlazada.
    
    push(a, 444);
    push(a, 6969);
    
    return(0);
}

t_stack *ft_init_t_stack(void)
{
    t_stack *stack;
    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->prev = NULL;
    stack->next = NULL;
    stack->data = 0;

    return(stack);
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

int main(int argc, char **argv)
{
    t_stack *t_stack_a;
    //t_stack *t_stack_b;
    char **splitted;

    splitted = NULL;
    if (argc < 2)
    {
        ft_error("No hay argumentos");
        return(0);
    }

    if (argc == 2)
    {
        if (ft_space_checker(argv[1]) == 0)
        {
            printf("OK\n");
            return (-1);
        }
        //if (ft_space_checker(argv[1]) > 0)
        //{
        //    splitted = ft_splitter((const char *)argv[1]); //no furula aún
       // }
    }
    
    t_stack_a = ft_init_t_stack(); //init t_stack reserva memoria para un t_stack e inicializa su dato a 0 y sus punteros a NULL
    //t_stack_b = ft_init_t_stack();

    if (splitted == NULL)
        splitted = argv;

    if(ft_args_array(argc, splitted, t_stack_a) == -1)     //recolectar los args en un array de ints (atoi) mientras vamos comprobando que los args son números positivos o negativos. Hay que comprobar también si los números están duplicados
    {
        ft_error("Los argumentos han de ser númericos.");
        exit(0);
    }
    //ft_stack_printer(t_stack_a);
    
    free(t_stack_a);

    printf("%s", "cool\n");
}