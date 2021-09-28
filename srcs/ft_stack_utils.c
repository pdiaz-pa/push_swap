/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:45 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/28 14:45:56 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_last_lst(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

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

void	ft_sort_selector(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->next != NULL)
	{
		if (ft_size_selector(stack_a) == 2)
			ft_sort_two(stack_a);
		if (ft_size_selector(stack_a) == 3)
			ft_sort_three(stack_a);
		if (ft_size_selector(stack_a) == 4)
			ft_sort_four(stack_a, stack_b);
		if (ft_size_selector(stack_a) == 5)
			ft_sort_five(stack_a, stack_b);
		if (ft_size_selector(stack_a) > 5)
			ft_sort_lot(stack_a, stack_b);
	}
	//if (stack_a->next != NULL) //así solo imprime si van bien las cosas
	//	ft_stack_printer(stack_a);
    //if (stack_b->next != NULL) //así solo imprime si van bien las cosas
    //   ft_stack_printer(stack_b);
}

void	ft_make_list(t_stack *head, long long *nums, int array_size)
{
	int			idx;
	t_stack		*new_node;

	idx = 0;
	while (idx < array_size)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
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
