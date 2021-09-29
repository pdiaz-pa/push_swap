/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:16 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/29 15:10:26 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splitted;
	int		size;

	splitted = NULL;
	size = ft_arg_size(argv);
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (ft_space_checker(argv[1]) == 0)
			return (-1);
		if (ft_space_checker(argv[1]) > 0)
			splitted = ft_splitter(argv, size);
	}
	
	stack_a = ft_init_t_stack();
	stack_b = ft_init_t_stack();
	if (splitted == NULL)
	{
		if (ft_args_array(argv, stack_a, size, 0) == -1)
			return (0);
	}
	else
	{
		size = ft_arg_size(splitted);
		if (ft_args_array(splitted, stack_a, size, 1) == -1)
			return (0);
	}
	ft_sort_selector(stack_a, stack_b);
	//ft_stack_printer(stack_a);
	//ft_free_stacks(stack_a, stack_b);

	//system("leaks push_swap");

}
