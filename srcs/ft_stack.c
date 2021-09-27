/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:45 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/27 14:29:45 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_printer(t_stack *stack)
{
	while (stack)
	{
		/*if (stack->next != NULL && stack->next->data < stack->data && stack->data != 696969)
		{
			printf("%d stop!\n", stack->data);
			return ;
		}*/
		
		printf("%d->", stack->data);
		stack = stack->next;
	}
	printf("NULL\n");
}

t_stack	*ft_init_t_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->prev = NULL;
	stack->next = NULL;
	stack->data = 696969;
	return (stack);
}

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	t_stack	*nstack;

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
