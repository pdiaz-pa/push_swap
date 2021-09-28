/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:36 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/28 13:50:32 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	int	auxdata;

	if (stack_a->next == NULL)
		return ;
	auxdata = stack_a->next->data;
	pop(stack_a);
	ft_push_last(stack_a, auxdata);
	printf("%s", "ra\n");
}

void	rb(t_stack *stack_b)
{
	int	auxdata;

	if (stack_b->next == NULL)
		return ;
	auxdata = stack_b->next->data;
	pop(stack_b);
	ft_push_last(stack_b, auxdata);
	printf("%s", "rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	printf("%s", "rr\n");
}
