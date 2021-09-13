/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:16 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/13 15:12:21 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_dup(long long *nums, int argc)
{
    int i;
    int j;
    long long *checker;

    i = 1;
    j = 1;
    checker = nums;
    
    while (i != argc)
    {
        while (j != argc)
        {
            if (checker[j] == nums[i] && j != i)
            {
                printf("%lld ESTE SE REPITE!\n", checker[j]);
                return (-1);
            }
            j++;
        }
        j = 1;
        i++;
    }
    return(0);
}

void ft_error(char *str)
{
    printf("%s", "Error\n");
    printf("%s\n", str);
}

void ft_make_list(t_stack *head, long long *nums, int array_size)
{
	int		idx;
	t_stack	*new_node;

	idx = 0;
	while (idx < array_size - 1)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
        printf("%s", "Creando nodo...\n");
		if (!new_node)
			ft_error("fuckyou");
		if (head->next == NULL)
		{
			new_node->data = nums[idx++];
			new_node->next = NULL;
			new_node->prev = head;
			head->next = new_node;
            printf("%s", "EL PEPE\n");
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

int ft_args_array(int argc, char **argv, t_stack *a)
{
    int i;
    long long *nums;
    int j;
    int z;
    z = 0;
    i = 1;
    j = 0;
    nums = (long long *)malloc(sizeof(long long) * (argc + 1));
    
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
        printf("%lld data \n", nums[i]);
        j = 0;
        i++;
    }
    nums = reverse_array(nums, argc);
    nums[i++] = '\0';
    nums = ft_positivizer(nums); // si hay números negativos hace que el menor de ellos sea 0, así es más fácil trabajar luego
    if (ft_is_sort(nums, argc) == -1)
    {
        ft_error("Ya están ordenados.\n");
        return(-1);
    }
  
    if (ft_is_dup(nums, argc) == -1)
    {
        ft_error("No puede haber números duplicados.\n");
        return(-1);
    }
    while(nums[z] != '\0')
    {
        printf("%lld numeritos\n", nums[z]);
        z++;
    }
    ft_make_list(a, nums, i); //crea nodos por cada uno de los elementos del array que hemos creado y los enlaza para crear una lista enlazada.
    //push(a, 444);
    //push(a, 6969);
    return(0);
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

    i = 1;
    splitted = NULL;

    argc = argc - 1 + 1;
    while(i < argc)
    {

        splitted = ft_split(argv[1], ' '); // por algún motivo solo está guardando el segundo número
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
        ft_error("Los argumentos han de ser númericos, estar desordenados y no estar duplicados.");
        exit(0);
    }
    
    //push(stack_a, 123);
    if (stack_a->next != NULL) //así solo imprime si van bien las cosas
        ft_stack_printer(stack_a);

    if (stack_a->next != NULL) //así solo imprime si van bien las cosas
        if(ft_size_selector(stack_a) == 2)
            ft_sort_two(stack_a);
        if(ft_size_selector(stack_a) == 3)
            ft_sort_three(stack_a);
        if(ft_size_selector(stack_a) == 5)
            ft_sort_five(stack_a, stack_b);
        if(ft_size_selector(stack_a) > 5)
            ft_sort_lot(stack_a, stack_b);
    
    if (stack_a->next != NULL) //así solo imprime si van bien las cosas
        ft_stack_printer(stack_a);
    //ft_free_stacks(t_stack_a, t_stack_b);

    printf("%s", "cool\n");
}