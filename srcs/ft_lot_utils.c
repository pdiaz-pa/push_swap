/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lot_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:31:08 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 15:29:12 by pdiaz-pa         ###   ########.fr       */
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
		if ((ft_f_cnt(stack_b, max)) < half)
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

void	ft_use_frst(t_stack *a, t_stack *b, int hold_first, int half)
{
	if ((ft_f_cnt(a->next, hold_first)) < half)
	{
		while (a->next->data != hold_first)
			ra(a);
		pb(a, b);
	}
	else
	{
		while (a->next->data != hold_first)
			rra(a);
		pb(a, b);
	}
}

void	ft_use_sec(t_stack *a, t_stack *b, int hold_second, int half)
{
	if ((ft_s_cnt(a, hold_second)) < half)
	{
		while (a->next->data != hold_second)
			rra(a);
		pb(a, b);
	}
	else
	{
		while (a->next->data != hold_second)
			ra(a);
		pb(a, b);
	}
}

void	ft_a_to_b(t_stack *a, t_stack *b, int chk_div, int chk_mlt)
{
	int	size;
	int	h_f;
	int	h_s;
	int	chk_size;

	chk_size = (ft_max_finder(a)) / chk_div;
	while (ft_size_stack(a) > 1)
	{
		while (chk_mlt <= chk_div)
		{
			size = ft_size_stack(a);
			h_f = ft_first_finder(a, (chk_size * chk_mlt));
			h_s = ft_second_finder(a, (chk_size * chk_mlt), h_f);
			if (h_f != -1 || h_s != -1)
			{
				if ((h_s == -1) || (ft_f_cnt(a, h_f) < ft_s_cnt(a, h_s)))
					ft_use_frst(a, b, h_f, (size / 2));
				else
					ft_use_sec(a, b, h_s, (size / 2));
				if (ft_num_in_chunk(a, (chk_size * chk_mlt)) == 0)
					chk_mlt++;
			}
		}
		pb(a, b);
	}
}
