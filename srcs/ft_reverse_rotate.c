/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:33 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/17 12:22:33 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_stack *stack_a)
{
    int auxdata;
    t_stack *last;

    last = ft_find_last_lst(stack_a);
    auxdata = last->data;
    ft_pop_last(stack_a);
    ft_push_first(stack_a, auxdata);
    printf("%s", "rra\n");
}

void    rrb(t_stack *stack_b)
{
    int auxdata;
    t_stack *last;

    last = ft_find_last_lst(stack_b);
    auxdata = stack_b->next->data;
    ft_pop_last(stack_b);
    ft_push_first(stack_b, auxdata);
    printf("%s", "rrb\n");
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    printf("%s", "rrr\n");
}
