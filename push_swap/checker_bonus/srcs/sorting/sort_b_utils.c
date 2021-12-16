/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:34:46 by mac               #+#    #+#             */
/*   Updated: 2021/11/01 18:14:36 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_if_sorted(t_node **head_a, t_node **head_b)
{
	t_node	*current;

	if (*head_b != NULL)
		return (0);
	current = (*head_a)->next;
	if (*head_a == (*head_a)->next)
		return (1);
	while (1)
	{
		if (current->rank != current->previous->rank + 1)
			return (0);
		current = current->next;
		if (current == *head_a)
			break ;
	}
	if (*head_b == NULL)
		return (1);
	else
		return (0);
}

t_node	*find_partner_node(t_node *head_a, t_node *node_b)
{
	t_node	*current;

	current = head_a;
	while (1)
	{
		current = current->next;
		if (current->rank >= node_b->rank
			&& current->previous->rank <= node_b->rank)
			break ;
		if (current->previous->rank <= node_b->rank
			&& current->rank <= current->previous->rank)
			break ;
		if (current->rank >= node_b->rank
			&& current->rank <= current->previous->rank)
			break ;
	}
	return (current);
}

int	get_stack_size(t_node *head)
{
	t_node	*current;
	int		i;

	i = 0;
	current = head;
	while (1)
	{
		current->pos = i;
		current = current->next;
		if (current == head)
			break ;
		i++;
	}
	return (i);
}
