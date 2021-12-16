/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:05:52 by eozben            #+#    #+#             */
/*   Updated: 2021/11/01 18:27:51 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	reverse_rotate(t_node **head_a, t_node **head_b, int x)
{
	if (x == A)
	{
		if (head_a == NULL || *head_a == NULL)
			return (0);
		*head_a = (*head_a)->previous;
	}
	if (x == B)
	{
		if (head_b == NULL || *head_b == NULL)
			return (0);
		*head_b = (*head_b)->previous;
	}
	return (1);
}

int	reverse_rotate_both(t_node **head_a, t_node **head_b)
{
	reverse_rotate(head_a, head_b, A);
	reverse_rotate(head_a, head_b, B);
	return (1);
}

int	rotate(t_node **head_a, t_node **head_b, int x)
{
	if (x == A)
	{
		if (head_a == NULL || *head_a == NULL)
			return (0);
		*head_a = (*head_a)->next;
	}
	if (x == B)
	{
		if (head_b == NULL || *head_b == NULL)
			return (0);
		*head_b = (*head_b)->next;
	}
	return (1);
}

int	rotate_both(t_node **head_a, t_node **head_b)
{
	rotate(head_a, head_b, A);
	rotate(head_a, head_b, B);
	return (1);
}
