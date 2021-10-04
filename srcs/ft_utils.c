/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:40 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 14:49:54 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == 'r' || c == '\t'
		||c == '\v' || c == ' ');
}

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

long long	ft_atoll(char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (ft_isalpha(*str))
		return (-9999999999999);
	return (sign * result);
}

long long	*reverse_array(long long *nums, int size)
{
	int	i;
	int	t;
	int	k;

	i = 0;
	t = 0;
	k = 0;
	while (k < (size / 2))
	{
		t = nums[i];
		nums[i] = nums[size - k - 1];
		nums[size - k - 1] = t;
		k++;
		i++;
	}
	return (nums);
}
