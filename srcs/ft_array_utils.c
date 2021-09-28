/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:55:43 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/28 15:48:04 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_arr_size(char **split_arr)
{
	int	idx;

	idx = 0;
	while (split_arr[idx])
		idx++;
	return (idx);
}

int	ft_arg_size(char **splitted)
{
	int	size;

	size = 0;
	while (splitted[size] != '\0')
		size++;
	return (size);
}

int	ft_args_array(char **splitted, t_stack *a, int size, int argv_or_splitted)
{
	int			i;
	long long	*nums;
	int			j;
	int			z;

	z = 0;
	if (argv_or_splitted == 1)
		i = 0;
	else
		i = 1;
	j = 0;
	nums = (long long *)malloc(sizeof(long long) * (size + 1));
	while (splitted[i] != '\0')
	{
		while (splitted[i][j] != '\0')
		{
			if (ft_isdigit(splitted[i][j]) == -1)
			{
				printf("%s", "Error\n");
				//ft_error("Los argumentos han de ser númericos.\n");
				return (-1);
			}
			j++;
		}
		j = 0;
		nums[z] = ft_atoll(splitted[i]);
		/*printf("%d ---", z);
		printf("%lld data \n", nums[z]);*/
		i++;
		z++;
	}
	if (argv_or_splitted == 1)
		nums = reverse_array(nums, (size));
	else
		nums = reverse_array(nums, (size - 1));
	nums[z++] = '\0';
	z = 0;
	nums = ft_positivizer(nums, size);
	if (ft_is_dup(nums, (size - 1)) == -1)
	{
		printf("%s", "Error\n");
		return (-1);
	}
	if (ft_is_sort(nums, size) == -1)
		return (-1);
	if (argv_or_splitted == 1)
		ft_make_list(a, nums, size);
	else
		ft_make_list(a, nums, (size - 1));
	return (0);
}
