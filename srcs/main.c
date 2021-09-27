/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:16 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/27 17:01:44 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_dup(long long *nums, int argc)
{
    int i;
    int j;
    long long *checker;

    i = 0;
    j = 0;
    checker = nums;
    
    while (i != argc)
    {
        while (j != argc)
        {
            if (checker[j] == nums[i] && j != i)
            {
                //printf("%lld ESTE SE REPITE!\n", checker[j]);
                return (-1);
            }
            j++;
        }
        j = 0;
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

	while (idx < array_size)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
        //printf("%s", "Creando nodo...\n");
		if (!new_node)
			printf("%s", "fuckyou");
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

int ft_max_min_int(long long *nums, int size)
{
    int i;
    
    i = 0;
    while (nums[i] < size)
    {
        if (nums[i] > 2147483647 || nums[i] < -2147483648)
        {
            //printf("%d la i\n", i);
            //printf("%lld el num\n", nums[i]);
            return(-1);
        }
        i++;
    }
    return(0);
}

int ft_args_array(int argc, char **splitted, t_stack *a, int size, int argv_or_splitted)
{
    int i;
    long long *nums;
    int j;
    int z;

    z = 0;
    if (argv_or_splitted == 1)
        i = 0;
    else
        i = 1;
    j = 0;
 
    nums = (long long *)malloc(sizeof(long long) * (size + 1));
    
    while (splitted[i] != '\0')
    {
        //printf("%s\n", splitted[i]);
        while(splitted[i][j] != '\0')
        {
            if (ft_isdigit(splitted[i][j]) == -1)
            {
                //write(1, &splitted[i][j], 1);
                printf("%s", "Error\n");
                //ft_error("Los argumentos han de ser númericos.\n");
                return(-1);
            }
            j++;
        }
        j = 0;
        nums[z] = ft_atoll(splitted[i]);
        //printf("%lld data \n", nums[z]);
        i++;
        z++;
    }
    if (argv_or_splitted == 1)
        nums = reverse_array(nums, (size));
    else
        nums = reverse_array(nums, (argc - 1));
    
    nums[z++] = '\0';
    z = 0;
/*    if (argv_or_splitted == 1)
    {
        if (ft_max_min_int(nums, size) == -1)
        {
            printf("%s", "Error\n");
            printf("%s", "maxminint\n");
            return(-1);
        }
    }
    else
    {
        if (ft_max_min_int(nums, size - 1) == -1)
        {
            printf("%s", "Error\n");
            printf("%s", "maxminint\n");
            return(-1);
        }
    }
*/
    nums = ft_positivizer(nums); // si hay números negativos hace que el menor de ellos sea 0, así es más fácil trabajar luego
    if (ft_is_dup(nums, (size - 1)) == -1)
    {
        printf("%s", "Error\n");
        //printf("%s", "dup\n");
        return(-1);
    }
    if (ft_is_sort(nums, size) == -1)
    {
        //printf("%s", "Error\n");
        return(-1);
    }
    if (argv_or_splitted == 1)
        ft_make_list(a, nums, size); //crea nodos por cada uno de los elementos del array que hemos creado y los enlaza para crear una lista enlazada.
    else
        ft_make_list(a, nums, (size - 1)); //crea nodos por cada uno de los elementos del array que hemos creado y los enlaza para crear una lista enlazada.

    return(0);
}

int		ft_split_arr_size(char **split_arr)
{
	int idx;

	idx = 0;
	while (split_arr[idx])
		idx++;
	return (idx);
}


char **ft_splitter(char **argv, int argc)
{
    char **splitted;
    int i;
    int j;
    j = 0;
    i = 0;
    splitted = NULL;

    while(i < argc)
    {
        splitted = ft_split(argv[i], ' ');
        i++;
    }
    
    i = 0;
/*
    while (splitted[i] != '\0')
    {
        while(splitted[i][j] != '\0')
        {
            write(1, &splitted[i][j], 1);
            j++;
        }
        printf("%s", " CHR\n");
        j = 0;
        i++;
    }*/
    return(splitted);
}

int ft_arg_size(char **splitted)
{
    int size;
    size = 0;

    while(splitted[size] != '\0')
    {
        //printf("%d SIZE\n", size);
        //printf("%s waju\n", splitted[size]);
        size++;
    }
        //printf("%d FINAL SIZE\n", size);
        //printf("%s\n", "----------------");
    
    return(size);
}


int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char **splitted;
    int size;
    
    splitted = NULL;
    size = ft_arg_size(argv);
    
    
    if (argc < 2)
        return(0);
    if (argc == 2)
    {
        if (ft_space_checker(argv[1]) == 0)
        {
            //printf("OK\n");
            return (-1);
        }
        if (ft_space_checker(argv[1]) > 0)
        {
            //printf("entiendo que hay comillas y espacios y thal\n");
            splitted = ft_splitter(argv, size);
        }
    }
    stack_a = ft_init_t_stack(); //init t_stack reserva memoria para un stack e inicializa su dato a 0 y sus punteros a NULL
    stack_b = ft_init_t_stack();
    if (splitted == NULL)
    {
        //printf("%s", "NO COMILLAS\n");
        if (ft_args_array(argc, argv, stack_a, size, 0) == -1)     //recolectar los args en un array de ints (atoi) mientras vamos comprobando que los args son números positivos o negativos. Hay que comprobar también si los números están duplicados
        {
            //ft_error("Los argumentos han de ser númericos, estar desordenados y no estar duplicados.");
            return(0);
        }
    }
    else
    {
        size = ft_arg_size(splitted);
        if (ft_args_array(argc, splitted, stack_a, size, 1) == -1)     //recolectar los args en un array de ints (atoi) mientras vamos comprobando que los args son números positivos o negativos. Hay que comprobar también si los números están duplicados
        {
            //ft_error("Los argumentos han de ser númericos, estar desordenados y no estar duplicados.");
            return(0);
        }
    }
    //if (stack_a->next != NULL) //así solo imprime si van bien las cosas
    //    ft_stack_printer(stack_a);
    if (stack_a->next != NULL) //así solo imprime si van bien las cosas
        if(ft_size_selector(stack_a) == 2)
            ft_sort_two(stack_a);
        if(ft_size_selector(stack_a) == 3)
            ft_sort_three(stack_a);
        if(ft_size_selector(stack_a) == 4)
            ft_sort_four(stack_a, stack_b);
        if(ft_size_selector(stack_a) == 5)
            ft_sort_five(stack_a, stack_b);
        if(ft_size_selector(stack_a) > 5)
            ft_sort_lot(stack_a, stack_b);
    //if (stack_a->next != NULL) //así solo imprime si van bien las cosas
     //   ft_stack_printer(stack_a);
    //if (stack_b->next != NULL) //así solo imprime si van bien las cosas
    //   ft_stack_printer(stack_b);
    //ft_free_stacks(stack_a, stack_b);
}
