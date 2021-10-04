/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:44:30 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/10/04 15:02:04 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **s, int idx)
{
	while (idx--)
		free(s[idx]);
	free(s);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	t_stack	*nstack;

	while (a)
	{
		nstack = a->next;
		free(a);
		a->next = NULL;
		a->prev = NULL;
		a = nstack;
	}
	while (b)
	{
		nstack = b->next;
		free(b);
		b->next = NULL;
		b->prev = NULL;
		b = nstack;
	}
}
