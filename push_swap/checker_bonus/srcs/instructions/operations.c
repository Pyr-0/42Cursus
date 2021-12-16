/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:33:43 by eozben            #+#    #+#             */
/*   Updated: 2021/11/01 18:27:59 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap_top(t_node **head)
{
	int	tmp;

	if (head == NULL || *head == NULL || (*head)->next == *head)
		return (0);
	tmp = (*head)->next->nb;
	(*head)->next->nb = (*head)->nb;
	(*head)->nb = tmp;
	tmp = (*head)->next->rank;
	(*head)->next->rank = (*head)->rank;
	(*head)->rank = tmp;
	return (1);
}

int	swap_both_tops(t_node **head_a, t_node **head_b)
{
	swap_top(head_a);
	swap_top(head_b);
	return (2);
}

int	push(int x, t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	if (x != PUSH_A && x != PUSH_B)
		return (0);
	if (x == PUSH_A && *head_b != NULL)
	{
		tmp = *head_b;
		detach_node(head_b, *head_b);
		attach_node(head_a, tmp);
		*head_a = (*head_a)->previous;
	}
	else if (x == PUSH_B && *head_a != NULL)
	{
		tmp = *head_a;
		detach_node(head_a, *head_a);
		attach_node(head_b, tmp);
		*head_b = (*head_b)->previous;
	}
	return (1);
}
