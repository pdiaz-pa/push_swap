/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:45 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 14:59:54 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_printer(t_stack *stack)
{
	while (stack)
	{
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

void	ft_make_list(t_stack *head, long long *nums, int array_size)
{
	int			i;
	t_stack		*new_node;

	i = 0;
	while (i < array_size)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			printf("%s", "fuckyou");
		if (head->next == NULL)
		{
			new_node->data = nums[i++];
			new_node->next = NULL;
			new_node->prev = head;
			head->next = new_node;
		}
		else
		{
			new_node->data = nums[i++];
			new_node->next = head->next;
			new_node->next->prev = new_node;
			new_node->prev = head;
			head->next = new_node;
		}
	}
}
