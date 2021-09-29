/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:42 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/29 16:11:01 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_two(t_stack *stack_a)
{
	if (stack_a->next->data > stack_a->next->next->data)
		sa(stack_a);
	return (0);
}

int	ft_sort_three(t_stack *a)
{
	if (a->next->data > a->next->next->data
		&& a->next->next->data < a->next->next->next->data
		&& a->next->next->next->data > a->next->data)
		sa(a);
	if ((a->next->data > a->next->next->data)
		&& (a->next->next->data > a->next->next->next->data)
		&& (a->next->next->next->data < a->next->data))
	{
		sa(a);
		rra(a);
	}
	if ((a->next->data > a->next->next->data)
		&& (a->next->next->data < a->next->next->next->data)
		&& (a->next->next->next->data < a->data))
		ra(a);
	if ((a->next->data < a->next->next->data)
		&& (a->next->next->data > a->next->next->next->data)
		&& (a->next->next->next->data > a->next->data))
	{
		sa(a);
		ra(a);
	}
	if ((a->next->data < a->next->next->data)
		&& (a->next->next->data > a->next->next->next->data)
		&& (a->next->next->next->data < a->next->data))
		rra(a);
	return (0);
}

int	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;

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
	return (0);
}

int	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;

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
	return (0);
}

int	ft_sort_lot(t_stack *stack_a, t_stack *stack_b, int hundred)
{
	int	chunk_multiplier;
	int chk_div;
	
	if (hundred == 1)
		chk_div = 5;
	else
		chk_div = 7;

	chunk_multiplier = 1;
	ft_a_to_b(stack_a, stack_b, chk_div, chunk_multiplier);
	ft_b_to_a(stack_a, stack_b);
	ft_adjusting(stack_a, stack_b);
	return (0);
}
