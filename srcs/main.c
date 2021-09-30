/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:16 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/30 14:18:21 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_error(int ret)
{
	write(1, "Error\n", 6);
	exit(ret);
	return (ret);
}


void		ft_arr_put(char **split_arr, long long *int_arr,
							int *jdx, int arr_size)
{
	int			split_size;
	int			split_idx;
	long long	tmp;

	split_size = ft_split_arr_size(split_arr);
	if (split_size > 1)
	{
		split_idx = 0;
		while (split_idx < split_size)
		{
			tmp = ft_atoll(split_arr[split_idx++]);
			int_arr[arr_size - 1 - *jdx] = tmp;
			*jdx += 1;
		}
	}
	else
	{
		tmp = ft_atoll(*split_arr);
		int_arr[arr_size - 1 - *jdx] = tmp;
		*jdx += 1;
	}
}

void		ft_init_arr(char **av, long long *int_arr, int ac, int arr_size)
{
	int			idx;
	int			jdx;
	char		**split_arr;

	idx = 1;
	jdx = 0;
	while (idx < ac)
	{
		split_arr = ft_split(av[idx], ' ');
		ft_arr_put(split_arr, int_arr, &jdx, arr_size);
		free_str(split_arr);
		idx++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	long long *nums;
	int		size;

	stack_a = ft_init_t_stack();
	stack_b = ft_init_t_stack();
	size = ft_arg_size(argv, argc);

	nums = (long long *)malloc(sizeof(long long) * size);
	if (!int_array)
		ft_error(0);
	ft_init_arr(argv, int_array, argc, size);

	ft_make_list(stack_a, int_array, size);

	ft_sort_selector(stack_a, stack_b);
	//ft_stack_printer(stack_a);
	//ft_free_stacks(stack_a, stack_b);

	system("leaks push_swap");

}
