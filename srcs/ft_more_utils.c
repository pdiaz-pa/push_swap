/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:23 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/28 15:43:09 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_space_checker(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_num_counter(char *argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

int	ft_size_selector(t_stack *stack)
{
	int	nbr_nodes;

	nbr_nodes = 0;
	while (stack->next != NULL)
	{
		nbr_nodes++;
		stack = stack->next;
	}
	return (nbr_nodes);
}

long long	*ft_positivizer(long long *nums, int size)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < size)
	{
		if (nums[i] < min)
			min = nums[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		nums[i] = nums[i] + (min * -1);
		i++;
	}
	return (nums);
}

int	ft_size_stack(t_stack *head)
{
	t_stack	*aux;
	int		size;

	size = 0;
	aux = head->next;
	while (aux)
	{
		aux = aux->next;
		size += 1;
	}
	return (size);
}
