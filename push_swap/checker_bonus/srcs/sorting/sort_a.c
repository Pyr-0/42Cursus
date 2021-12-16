/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:46:19 by mac               #+#    #+#             */
/*   Updated: 2021/11/01 19:38:42 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	order_a(t_node **head_a, int *results, int i, int x)
{
	int	ops;

	ops = 0;
	while (results[i])
	{
		if (i == BOTHDOWN)
		{
			ops += reverse_rotate(head_a, NULL, A);
			if (x == WRITE_INST)
				ft_putendl_fd("rra", 1);
		}
		else
		{
			ops += rotate(head_a, NULL, A);
			if (x == WRITE_INST)
				ft_putendl_fd("ra", 1);
		}
		results[i]--;
	}
	return (ops);
}

int	sort_stack_a(t_node **head_a, int x)
{
	t_node	*current;
	int		stacksize;
	int		results[2];
	int		i;

	stacksize = get_stack_size(*head_a);
	current = *head_a;
	while (1)
	{
		if (current->rank == 0)
			break ;
		current = current->next;
		if (current == *head_a)
			break ;
	}
	results[BOTHUP] = current->pos;
	results[BOTHDOWN] = stacksize - current->pos + 1;
	i = BOTHDOWN;
	if (results[BOTHUP] < results[BOTHDOWN])
		i = BOTHUP;
	return (order_a(head_a, results, i, x));
}
