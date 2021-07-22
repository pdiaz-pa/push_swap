/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:16 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/07/22 13:39:22 by pdiaz-pa         ###   ########.fr       */
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
	int		idx;
	t_stack	*new_node;

	idx = 0;
	while (idx < array_size - 1)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
    
		if (!new_node)
			ft_error("fuckyou");
		if (head->next == NULL)
		{
			new_node->data = nums[idx++];
			new_node->next = NULL;
			new_node->prev = head;
			head->next = new_node;
		}
		else
		{
			new_node->data = nums[idx++];
			new_node->next = head->next;
			new_node->next->prev = new_node;
			new_node->prev = head;
			head->next = new_node;
		}
	}
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
    nums = reverse_array(nums, argc);
    nums[i++] = '\0';
    if (ft_is_sort(nums, argc) == -1)
    {
        ft_error("Ya están ordenados.\n");
        return(-2);
    }


    ft_make_list(a, nums, i); //crea nodos por cada uno de los elementos del array que hemos creado y los enlaza para crear una lista enlazada.
    //push(a, 444);
    //push(a, 6969);
    
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

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	t_stack *nstack;

	while (a)
	{
		nstack = a->next;
		free(a);
		a->next = NULL;
		a->prev = NULL;
		a = nstack;
	}
	while (b)
	{
		nstack = b->next;
		free(b);
		b->next = NULL;
		b->prev = NULL;
		b = nstack;
	}
}

/*
char **ft_argv_to_splitted(char **argv, char **splitted, int argc)
{
    int i;
    int j;
    int k;

    i = 1;
    j = 0;
    k = 0;
    splitted = (char **) malloc(sizeof(char *) * (argc + 1));

    while(i < argc)
    {
        while(argv[i][j] != '\0')
        {
            argv[i][j] = splitted[k][j];
            j++;

        }
        splitted[k][j] = '\0';
        j = 0;
        i++;
        k++;
    }
    splitted[k][j] = '\0';
    return(splitted);
}*/

char **ft_splitter(char **argv, int argc)
{
    char **splitted;
    int i;

    i = 0;
    splitted = NULL;

    while(i < argc)
    {
        splitted = ft_split(argv[i], ' '); // por algún motivo solo está guardando el segundo número
        i++;
    }

    return(splitted);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
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
        if (ft_space_checker(argv[1]) > 0)
        {
            printf("entiendo que hay comillas y espacios y thal\n");
            splitted = ft_splitter(argv, argc);
        }
    }
    
    stack_a = ft_init_t_stack(); //init t_stack reserva memoria para un stack e inicializa su dato a 0 y sus punteros a NULL
    stack_b = ft_init_t_stack();

    if (splitted == NULL)
        splitted = argv;

    if(ft_args_array(argc, splitted, stack_a) == -1)     //recolectar los args en un array de ints (atoi) mientras vamos comprobando que los args son números positivos o negativos. Hay que comprobar también si los números están duplicados
    {
        ft_error("Los argumentos han de ser númericos.");
        exit(0);
    }

    if (stack_a->next != NULL) //así solo imprime si van bien las cosas
        ft_stack_printer(stack_a);
    
    //ft_free_stacks(t_stack_a, t_stack_b);
    //ft_size_selector(stack_a, stack_b, argc);
    printf("%s", "cool\n");
}