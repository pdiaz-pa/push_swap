/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_and_finder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:33:38 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 15:26:15 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_first_finder(t_stack *stack_a, int max_num)
{
	int	hold_first;

	hold_first = -1;
	while (hold_first == -1 && stack_a->next != NULL)
	{
		if (stack_a->data < max_num)
		{
			hold_first = stack_a->data;
		}
		stack_a = stack_a->next;
	}
	return (hold_first);
}

int	ft_second_finder(t_stack *stack_a, int max_num, int hold_first)
{
	int	hold_second;

	hold_second = -1;
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	while (hold_second == -1 && stack_a->prev != NULL)
	{
		if (stack_a->data < max_num && stack_a->data < hold_first)
		{
			hold_second = stack_a->data;
		}
		stack_a = stack_a->prev;
	}
	return (hold_second);
}

int	ft_f_cnt(t_stack *stack, int hold_first)
{
	int	count;

	count = 0;
	while (stack->data != hold_first)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	ft_s_cnt(t_stack *stack, int hold_second)
{
	int	count;

	count = 0;
	while (stack->next != NULL)
		stack = stack->next;
	while (stack->data != hold_second)
	{
		stack = stack->prev;
		count++;
	}
	return (count);
}

int	ft_num_in_chunk(t_stack *stack, int max_num)
{
	int	count;

	count = 0;
	while (stack->next)
	{
		if (stack->data < max_num)
			count++;
		stack = stack->next;
	}
	return (count);
}
