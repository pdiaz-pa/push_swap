/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:15:01 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/20 12:47:42 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    return (min);
}

int ft_sec_min_finder(t_stack *stack_a, int max, int min)
{
    int sec_min;

    sec_min = max;
    stack_a = stack_a->next;
    while(stack_a != NULL)
    {
        if ((stack_a->data < sec_min) && (sec_min != min))
            sec_min = stack_a->data;
        stack_a = stack_a->next;
    }
    return (min);
}
