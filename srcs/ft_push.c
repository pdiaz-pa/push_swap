/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:29 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/22 14:16:10 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int auxdata;

    size = ft_size_stack(stack_b);
    if (size < 2)
        return ;
    auxdata = stack_b->next->data;
    pop(stack_b);
    ft_push_first(stack_a, auxdata);
    printf("%s", "pa\n");
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    int size;
    int auxdata;

    size = ft_size_stack(stack_a);
    if (size < 2)
        return ;
    auxdata = stack_a->next->data;
    pop(stack_a);
    ft_push_first(stack_b, auxdata);
    printf("%s", "pb\n");
}