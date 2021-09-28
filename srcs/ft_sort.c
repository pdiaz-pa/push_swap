/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:42 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/28 15:27:07 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_two(t_stack *stack_a)
{
	if (stack_a->next->data > stack_a->next->next->data)
		sa(stack_a);
	return (0);
}

int	ft_sort_three(t_stack *stack_a)
{
	if (stack_a->next->data > stack_a->next->next->data
		&& stack_a->next->next->data < stack_a->next->next->next->data
		&& stack_a->next->next->next->data > stack_a->next->data)
	{
		sa(stack_a);
		return (0);
	}
	if ((stack_a->next->data > stack_a->next->next->data)
		&& (stack_a->next->next->data > stack_a->next->next->next->data)
		&& (stack_a->next->next->next->data < stack_a->next->data))
	{
		sa(stack_a);
		rra(stack_a);
		return (0);
	}
	if ((stack_a->next->data > stack_a->next->next->data)
		&& (stack_a->next->next->data < stack_a->next->next->next->data)
		&& (stack_a->next->next->next->data < stack_a->data))
	{
		ra(stack_a);
		return (0);
	}
	if ((stack_a->next->data < stack_a->next->next->data)
		&& (stack_a->next->next->data > stack_a->next->next->next->data)
		&& (stack_a->next->next->next->data > stack_a->next->data))
	{
		sa(stack_a);
		ra(stack_a);
		return (0);
	}
	if ((stack_a->next->data < stack_a->next->next->data)
		&& (stack_a->next->next->data > stack_a->next->next->next->data)
		&& (stack_a->next->next->next->data < stack_a->next->data))
	{
		rra(stack_a);
		return (0);
	}
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

int	ft_where_min(t_stack *stack_a, int min)
{
	t_stack	*aux;
	int		size;

	size = 0;
	aux = stack_a->next;
	while (aux->data != min)
	{
		aux = aux->next;
		size += 1;
	}
	return (size);
}

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

int	ft_first_count(t_stack *stack, int hold_first)
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

int	ft_second_count(t_stack *stack, int hold_second)
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

void	ft_a_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_size, int chunk_multiplier)
{
	int	size;
	int	half;
	int	hold_first;
	int	hold_second;

	while (ft_size_stack(stack_a) > 1)
	{
		while (chunk_multiplier <= 5)
		{
			size = ft_size_stack(stack_a);
			half = size / 2;
			hold_first = ft_first_finder(stack_a, (chunk_size * chunk_multiplier));
			hold_second = ft_second_finder(stack_a, (chunk_size * chunk_multiplier), hold_first);
			if (hold_first != -1 || hold_second != -1)
			{
				if ((hold_second == -1) || (ft_first_count(stack_a, hold_first) < ft_second_count(stack_a, hold_second)))
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
				else
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
				if (ft_num_in_chunk(stack_a, (chunk_size * chunk_multiplier)) == 0)
					chunk_multiplier++;
			}
		}
		pb(stack_a, stack_b);
	}
}

int	ft_sort_lot(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	chunk_multiplier;

	chunk_size = (ft_max_finder(stack_a)) / 5;
	chunk_multiplier = 1;
	ft_a_to_b(stack_a, stack_b, chunk_size, chunk_multiplier);
	ft_b_to_a(stack_a, stack_b);
	ft_adjusting(stack_a, stack_b);
	return (0);
}
