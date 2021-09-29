/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lot_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:31:08 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/29 16:05:08 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	max;
	int	min;
	int	size;
	int	half;

	while (ft_size_stack(stack_b) != 1)
	{
		size = ft_size_stack(stack_b);
		half = size / 2;
		max = ft_max_finder(stack_b);
		min = ft_min_finder(stack_b, max);
		if ((ft_first_count(stack_b, max)) < half)
		{
			while (stack_b->next->data != max)
				rb(stack_b);
			pa(stack_a, stack_b);
		}
		else
		{
			while (stack_b->next->data < max)
				rrb(stack_b);
			pa(stack_a, stack_b);
		}
	}
}

void	ft_adjusting(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
	rra(stack_a);
	rra(stack_a);
	if (stack_a->next->data > stack_a->next->next->data)
		sa(stack_a);
	rra(stack_a);
	if (stack_a->next->data > stack_a->next->next->data)
		sa(stack_a);
	rra(stack_a);
	if (stack_a->next->data > stack_a->next->next->data)
		sa(stack_a);
	ra(stack_a);
	ra(stack_a);
	ra(stack_a);
	ra(stack_a);
}

void	ft_use_first(t_stack *stack_a, t_stack *stack_b, int hold_first, int half)
{
	if ((ft_first_count(stack_a->next, hold_first)) < half)
	{
		while (stack_a->next->data != hold_first)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (stack_a->next->data != hold_first)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	ft_use_second(t_stack *stack_a, t_stack *stack_b, int hold_second, int half)
{
	if ((ft_second_count(stack_a, hold_second)) < half)
	{
		while (stack_a->next->data != hold_second)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while (stack_a->next->data != hold_second)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	ft_a_to_b(t_stack *a, t_stack *b, int chk_div, int chk_multiplier)
{
	int	size;
	int	half;
	int	hold_f;
	int	hold_s;
	int chk_size;
	chk_size = (ft_max_finder(a)) / chk_div;
	while (ft_size_stack(a) > 1)
	{
		while (chk_multiplier <= chk_div)
		{
			size = ft_size_stack(a);
			half = size / 2;
			hold_f = ft_first_finder(a, (chk_size * chk_multiplier));
			hold_s = ft_second_finder(a, (chk_size * chk_multiplier), hold_f);
			if (hold_f != -1 || hold_s != -1)
			{
				if ((hold_s == -1) || (ft_first_count(a, hold_f)
						< ft_second_count(a, hold_s)))
					ft_use_first(a, b, hold_f, half);
				else
					ft_use_second(a, b, hold_s, half);
				if (ft_num_in_chunk(a, (chk_size * chk_multiplier)) == 0)
					chk_multiplier++;
			}
		}
		pb(a, b);
	}
}