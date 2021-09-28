/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:31 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/28 14:34:08 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack *head)
{
	t_stack	*del;

	del = head->next;
	if (del == NULL)
		return ;
	if (del->next == NULL)
	{
		head->next = del->next;
		free (del);
	}
	else
	{
		del->next->prev = head;
		head->next = del->next;
		free (del);
	}
}

void	ft_pop_last(t_stack *head)
{
	t_stack	*del;

	del = head->next;
	if (del == NULL)
		return ;
	else
	{
		del = ft_find_last_lst(head);
		del->prev->next = NULL;
		free (del);
	}
}
