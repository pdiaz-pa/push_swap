/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:55:43 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 16:27:57 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checking_nums(long long *nums, int size)
{
	if (ft_is_dup(nums, size) == -1)
		return (-1);
	if (ft_is_sort(nums, size) == -1)
		return (-2);
	if (ft_max_min_int(nums, size - 1) == -1)
		return (-1);
	return (0);
}

long long	ft_put_sel(long long *nums, int *j, int arr_size, char **splitted)
{
	int			split_count;
	long long	tmp;
	int			split_size;

	split_size = ft_split_nums_size(splitted);
	if (split_size > 1)
	{
		split_count = 0;
		while (split_count < split_size)
		{
			tmp = ft_atoll(splitted[split_count++]);
			nums[arr_size - 1 - *j] = tmp;
			*j += 1;
		}
	}
	else
	{
		tmp = ft_atoll(*splitted);
		nums[arr_size - 1 - *j] = tmp;
		*j += 1;
	}
	if (tmp == -9999999999999)
		return (-9999999999999);
	return (0);
}

long long	ft_arr_put(char **splitted, long long *nums,
							int *j, int arr_size)
{
	if (ft_put_sel(nums, j, arr_size, splitted) == -9999999999999)
		return (-9999999999999);
	return (0);
}

long long	ft_init_nums(char **argv, long long *nums, int argc, int size)
{
	int			i;
	int			j;
	char		**splitted;

	i = 1;
	j = 0;
	while (i < argc)
	{
		splitted = ft_split(argv[i], ' ');
		if (ft_arr_put(splitted, nums, &j, size) == -9999999999999)
			return (-9999999999999);
		free_str(splitted);
		i++;
	}
	return (0);
}

int	ft_arg_size(char **argv, int argc)
{
	int		size;
	int		i;
	int		split_size;
	char	**splitted;

	size = 0;
	i = 0;
	while (i < argc)
	{
		splitted = ft_split(argv[i], ' ');
		split_size = ft_split_nums_size(splitted);
		size += split_size;
		free_str(splitted);
		i++;
	}
	return (size - 1);
}
