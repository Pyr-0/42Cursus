/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:33:07 by mac               #+#    #+#             */
/*   Updated: 2021/11/01 18:30:24 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_node	*find_best_node(t_node *head_b)
{
	t_node	*current;
	t_node	*best_node;
	int		lowest_actions;

	current = head_b;
	lowest_actions = head_b->actions_for_push;
	while (1)
	{
		if (current->actions_for_push < lowest_actions)
		{
			lowest_actions = current->actions_for_push;
			best_node = current;
		}
		current = current->next;
		if (current == head_b)
			break ;
	}
	return (best_node);
}

static int	compare_results(t_node *node, int *results)
{
	int	i;
	int	best_result;

	i = 0;
	best_result = -1;
	while (i < 4)
	{
		if (results[i] < best_result || best_result == -1)
		{
			best_result = results[i];
			node->actions_for_push = results[i];
			node->method_for_push = i;
		}
		i++;
	}
	return (best_result);
}

int	find_min_moves(t_node *node, t_node **head_a, t_node **head_b)
{
	int	stacksizes[2];
	int	results[4];

	stacksizes[A] = get_stack_size(*head_a);
	stacksizes[B] = get_stack_size(*head_b);
	if (node->pos >= node->partner->pos)
		results[BOTHUP] = node->pos;
	else
		results[BOTHUP] = node->partner->pos;
	if (stacksizes[B] - node->pos > stacksizes[A] - node->partner->pos)
		results[BOTHDOWN] = stacksizes[B] - node->pos + 1;
	else
		results[BOTHDOWN] = stacksizes[A] - node->partner->pos + 1;
	results[ADOWNBUP] = node->pos + (stacksizes[A] - node->partner->pos + 1);
	results[AUPBDOWN] = node->partner->pos + (stacksizes[B] - node->pos + 1);
	return (compare_results(node, results));
}

static void	mark_stack_b(t_node **head_a, t_node **head_b)
{
	t_node	*current;

	current = *head_b;
	while (1)
	{
		current->partner = find_partner_node(*head_a, current);
		find_min_moves(current, head_a, head_b);
		current = current->next;
		if (current == *head_b)
			break ;
	}
}

int	sort_stack_b(t_node **head_a, t_node **head_b, int x)
{
	t_node	*node_to_push;
	int		ops;

	ops = 0;
	while (*head_b != NULL)
	{
		mark_stack_b(head_a, head_b);
		node_to_push = find_best_node(*head_b);
		ops += push_best_node(node_to_push, head_a, head_b, x);
	}
	return (ops);
}
