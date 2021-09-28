/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:28:29 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2021/09/28 15:31:10 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_first(t_stack *head, int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		printf("%s", "Error push first");
		return ;
	}
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

void	ft_push_last(t_stack *head, int data)
{
	t_stack	*new_node;
	t_stack	*tmp_last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		printf("%s", "Error push first");
		return ;
	}
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

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	auxdata;

	size = ft_size_stack(stack_b);
	if (size < 1)
		return ;
	auxdata = stack_b->next->data;
	pop(stack_b);
	ft_push_first(stack_a, auxdata);
	printf("%s", "pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	auxdata;

	size = ft_size_stack(stack_a);
	if (size < 1)
		return ;
	auxdata = stack_a->next->data;
	pop(stack_a);
	ft_push_first(stack_b, auxdata);
	printf("%s", "pb\n");
}
