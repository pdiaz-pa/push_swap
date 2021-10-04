/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:19:29 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 15:28:20 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_three_onemove(t_stack *a)
{
	if ((a->next->data < a->next->next->data)
		&& (a->next->next->data > a->next->next->next->data)
		&& (a->next->next->next->data < a->next->data))
	{
		rra(a);
		return (0);
	}
	if (a->next->data > a->next->next->data
		&& a->next->next->data < a->next->next->next->data
		&& a->next->next->next->data > a->next->data)
	{
		sa(a);
		return (0);
	}
	if ((a->next->data > a->next->next->data)
		&& (a->next->next->data < a->next->next->next->data)
		&& (a->next->next->next->data < a->data))
	{
		ra(a);
		return (0);
	}
	return (0);
}

int	ft_sort_three(t_stack *a)
{
	ft_three_onemove(a);
	if ((a->next->data > a->next->next->data)
		&& (a->next->next->data > a->next->next->next->data)
		&& (a->next->next->next->data < a->next->data))
	{
		sa(a);
		rra(a);
		return (0);
	}
	if ((a->next->data < a->next->next->data)
		&& (a->next->next->data > a->next->next->next->data)
		&& (a->next->next->next->data > a->next->data))
	{
		sa(a);
		ra(a);
		return (0);
	}
	return (0);
}
