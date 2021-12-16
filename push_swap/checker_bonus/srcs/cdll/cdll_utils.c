/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:11:13 by eozben            #+#    #+#             */
/*   Updated: 2021/11/01 18:27:10 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*cdll_append(t_node **head)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	attach_node(head, newnode);
	return (newnode);
}

void	attach_node(t_node **head, t_node *newnode)
{
	if (*head == NULL)
	{
		*head = newnode;
		newnode->next = newnode;
		newnode->previous = newnode;
	}
	else
	{
		(*head)->previous->next = newnode;
		newnode->previous = (*head)->previous;
		(*head)->previous = newnode;
		newnode->next = *head;
	}
}

void	detach_node(t_node **head, t_node *node)
{
	node->next->previous = node->previous;
	node->previous->next = node->next;
	if (*head == node && (*head)->next == *head)
		*head = NULL;
	else if (*head == node)
		*head = node->next;
}

int	add_element(char *number, t_node **head)
{
	int	nb;

	if (!ft_isint(number))
		return (ERROR);
	nb = ft_atoi(number);
	cdll_append(head);
	(*head)->previous->nb = nb;
	(*head)->previous->actions_for_push = -1;
	return (0);
}

t_node	*copy_cdll(t_node **head)
{
	t_node	*original;
	t_node	*copy;

	copy = NULL;
	original = *head;
	if (*head == NULL)
		return (NULL);
	while (1)
	{
		cdll_append(&copy);
		copy->previous->nb = original->nb;
		copy->previous->rank = original->rank;
		original = original->next;
		if (original == *head)
			break ;
	}
	return (copy);
}
