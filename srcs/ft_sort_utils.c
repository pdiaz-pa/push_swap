/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:15:01 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 15:05:57 by pdiaz-pa         ###   ########.fr       */
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

int	ft_max_finder(t_stack *stack_a)
{
	int	max;

	max = 0;
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (stack_a->data > max)
			max = stack_a->data;
		stack_a = stack_a->next;
	}
	return (max);
}

int	ft_min_finder(t_stack *stack_a, int max)
{
	int	min;

	min = max;
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (stack_a->data < min)
			min = stack_a->data;
		stack_a = stack_a->next;
	}
	return (min);
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
		while (stack_a->next->data != min)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	while (stack_b->next != NULL)
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
}
