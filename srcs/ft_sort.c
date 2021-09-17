/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:42 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/17 15:11:03 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_sort_two(t_stack *stack_a)
{
    if (stack_a->next->data > stack_a->next->next->data)
        sa(stack_a);
    return(0);
}

int ft_sort_three(t_stack *stack_a)
{
    if(stack_a->next->data > stack_a->next->next->data &&
        stack_a->next->next->data < stack_a->next->next->next->data &&
        stack_a->next->next->next->data > stack_a->next->data) // 2 1 3 V
    {
        sa(stack_a);
        return(0);
    }

    if((stack_a->next->data > stack_a->next->next->data) &&
        (stack_a->next->next->data > stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data < stack_a->next->data)) // 3 2 1 v
    {
        sa(stack_a);
        rra(stack_a);
        return(0);
    }

    if((stack_a->next->data > stack_a->next->next->data) &&
        (stack_a->next->next->data < stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data < stack_a->data)) // 3 1 2 V
    {
        ra(stack_a);
        return(0);
    }
    if((stack_a->next->data < stack_a->next->next->data) &&
        (stack_a->next->next->data > stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data > stack_a->next->data)) // 1 3 2 V
    {
        sa(stack_a);
        ra(stack_a);
        return(0);
    }
    if((stack_a->next->data < stack_a->next->next->data) &&
        (stack_a->next->next->data > stack_a->next->next->next->data) &&
        (stack_a->next->next->next->data < stack_a->next->data)) // 2 3 1 V
    {
        rra(stack_a);
        return(0);    
    }
    return(0);
}

int ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
    int max;
    int min;

    max = ft_max_finder(stack_a);
    min = ft_min_finder(stack_a, max);
    while (stack_a->next->data != max)
        ra(stack_a);
    pb(stack_a, stack_b);
    while (stack_a->next->data != min)
        ra(stack_a);
    pb(stack_a, stack_b);
    ft_sort_two(stack_a);
    ft_sort_two(stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    ra(stack_a);

    return(0);
}

int ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
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
int ft_where_min(t_stack *stack_a, int min)
{
	t_stack *aux;
	int		size;

	size = 0;
	aux = stack_a->next;
	while (aux->data != min)
	{
		aux = aux->next;
		size += 1;
	}
	return (size);
}
int ft_sort_lot(t_stack *stack_a, t_stack *stack_b)
{
    int max;
    int min;
    int size;

    size = 0;
    //printf("%s", "Hay muchos nodos para ordenar.\n");

    while (ft_size_stack(stack_a) != 1)
    {
        size = ft_size_stack(stack_a);
        max = ft_max_finder(stack_a);
        min = ft_min_finder(stack_a, max);
        if (ft_where_min(stack_a, min) < (size / 2))
        {
            while(stack_a->next->data != min)
                ra(stack_a);
            pb(stack_a, stack_b);
        }
        else
        {
            while(stack_a->next->data != min)
                rra(stack_a);
            pb(stack_a, stack_b);
        }

    }
 
    while(stack_b->next)
    {
        pa(stack_a, stack_b);
    }
    
    return(0);
}