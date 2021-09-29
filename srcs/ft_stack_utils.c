/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:45 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/29 16:06:35 by pdiaz-pa         ###   ########.fr       */
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

void	ft_sort_generic(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;
	int	size;

	while (stack_a->next != NULL)
	{
		size = ft_size_stack(stack_a);
		max = ft_max_finder(stack_a);
		min = ft_min_finder(stack_a, max);
		//printf("%d min\n", min);
			while (stack_a->next->data != min)
				ra(stack_a);
		pb(stack_a, stack_b);
		
	}

	while(stack_b->next != NULL)
		pa(stack_a, stack_b);
}


void	ft_sort_selector(t_stack *a, t_stack *b)
{
	if (a->next != NULL)
	{
		if (ft_size_selector(a) == 2)
			ft_sort_two(a);
		if (ft_size_selector(a) == 3)
			ft_sort_three(a);
		if (ft_size_selector(a) == 4)
			ft_sort_four(a, b);
		if (ft_size_selector(a) == 5)
			ft_sort_five(a, b);
		if (ft_size_selector(a) == 100)
			ft_sort_lot(a, b, 1);
		if (ft_size_selector(a) == 500)
			ft_sort_lot(a, b, 0);
		if ((ft_size_selector(a) > 5 && ft_size_selector(a) < 100)
			|| (ft_size_selector(a) > 100 && ft_size_selector(a) < 500)
			|| ft_size_selector(a) > 500)
			ft_sort_generic(a, b);
		
	}
	//if (a->next != NULL) //así solo imprime si van bien las cosas
	//	ft_stack_printer(a);
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
