/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:56:31 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/13 14:42:46 by pdiaz-pa         ###   ########.fr       */
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

void	ft_push_first(t_stack *head, int data)
{
	t_stack *new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_error("Error push_first\n");
	if (head->next == NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = head;
		head->next = new_node;
	}
	else
	{
		new_node->data = data;
		new_node->next = head->next;
		head->next->prev = new_node;
		new_node->prev = head;
		head->next = new_node;
	}
}

t_stack	*ft_find_last_lst(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	ft_push_last(t_stack *head, int data)
{
	t_stack *new_node;
	t_stack *tmp_last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_error("Error push_last\n");
	tmp_last = ft_find_last_lst(head);
	if (head->next == NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = head;
		head->next = new_node;
	}
	else
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->prev = tmp_last;
		tmp_last->next = new_node;
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

void	ft_pop_last(t_stack *head)
{
	t_stack *del;

	del = head->next;
	if (del == NULL)
		return ;
	else
	{
		del = ft_find_last_lst(head);
		del->prev->next = NULL;
		free(del);
	}
}