/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:31 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/07/12 15:27:32 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack *head, int data)
{
    t_stack *node;
	
    node = (t_stack *)malloc(sizeof(t_stack));

        if (head->next == NULL)
        {
            node->data = data;            
            node->next = NULL;
            node->prev = head;
            head->next = node;
        }
        else
        {
            node->data = data;
            node->next = head->next;
            node->next->prev = node;
            head->next = node;
        }
}

void pop(t_stack *head)
{
	t_stack *del;

	del = head->next;
	if (del == NULL)
		return ;
	if (del->next == NULL)
	{
		head->next = del->next;
		free(del);
	}
	else
	{
		del->next->prev = head;
		head->next = del->next;
		free(del);
	}
}

