/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:55:43 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/30 11:07:01 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	ft_arg_size(char **argv, int argc)
{
	int		size;
	int		idx;
	int		split_size;
	char	**split_arr;

	size = 0;
	idx = 0;
	while (idx < argc)
	{
		split_arr = ft_split(argv[idx], ' ');
		split_size = ft_split_arr_size(split_arr);
		size += split_size;
		free_str(split_arr);
		idx++;
	}
	return (size - 1);
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
				return (-1);
			}
			j++;
		}
		j = 0;
		nums[z] = ft_atoll(splitted[i]);
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
	free(nums);
	return (0);
}
