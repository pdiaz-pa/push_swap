/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:16 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 16:25:23 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int ret)
{
	write(1, "Error\n", 6);
	exit(ret);
	return (ret);
}

int	ft_init_check_nums(char **argv, long long *nums, int argc, int size)
{
	if (ft_init_nums(argv, nums, argc, size) == -9999999999999)
	{
		printf("Error\n");
		return (-1);
	}
	if (ft_checking_nums(nums, size) == -1)
	{
		printf("Error\n");
		return (-1);
	}
	if (ft_checking_nums(nums, size) == -2)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	long long	*nums;
	int			size;

	stack_a = ft_init_t_stack();
	stack_b = ft_init_t_stack();
	size = ft_arg_size(argv, argc);
	if (argc < 2)
		return (0);
	nums = (long long *)malloc(sizeof(long long) * size);
	if (!nums)
		ft_error (0);
	if (ft_init_check_nums(argv, nums, argc, size) == -1)
		return (0);
	nums = ft_positivizer(nums, size);
	ft_make_list(stack_a, nums, size);
	ft_sort_selector(stack_a, stack_b);
}
