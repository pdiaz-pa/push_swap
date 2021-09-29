/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:27:38 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/29 11:34:54 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_dup(long long *nums, int size)
{
	int			i;
	int			j;
	long long	*checker;

	i = 0;
	j = 0;
	checker = nums;
	while (i != size)
	{
		while (j != size)
		{
			if (checker[j] == nums[i] && j != i)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ft_is_sort(long long *array, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < (size - 1))
		i++;
	while (k < i)
	{
		if (array[k] >= array[k + 1])
			j++;
		k++;
	}
	if (j == i)
		return (-1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
	{
		return (1);
	}
	else
		return (-1);
}

int	ft_max_min_int(long long *nums, int size)
{
	int	i;

	i = 0;
	while (nums[i] < size)
	{
		if (nums[i] > 2147483647 || nums[i] < -2147483648)
			return (-1);
		i++;
	}
	return (0);
}
