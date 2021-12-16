/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:05:09 by mac               #+#    #+#             */
/*   Updated: 2021/11/01 18:28:55 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	r_up(t_node **head_a, t_node **head_b, t_node *node, int x)
{
	int		operations;

	operations = 0;
	while ((*head_a)->rank != node->partner->rank
		&& (*head_b)->rank != node->rank)
	{
		operations += rotate_both(head_a, head_b);
		if (x == WRITE_INST)
			ft_putendl_fd("rr", 1);
	}
	while ((*head_a)->rank != node->partner->rank)
	{
		operations += rotate(head_a, head_b, A);
		if (x == WRITE_INST)
			ft_putendl_fd("ra", 1);
	}
	while ((*head_b)->rank != node->rank)
	{
		operations += rotate(head_a, head_b, B);
		if (x == WRITE_INST)
			ft_putendl_fd("rb", 1);
	}
	return (operations);
}

static int	rr_down(t_node **head_a, t_node **head_b, t_node *node, int x)
{
	int		operations;

	operations = 0;
	while ((*head_a)->rank != node->partner->rank
		&& (*head_b)->rank != node->rank)
	{
		operations += reverse_rotate_both(head_a, head_b);
		if (x == WRITE_INST)
			ft_putendl_fd("rrr", 1);
	}
	while ((*head_a)->rank != node->partner->rank)
	{
		operations += reverse_rotate(head_a, head_b, A);
		if (x == WRITE_INST)
			ft_putendl_fd("rra", 1);
	}
	while ((*head_b)->rank != node->rank)
	{
		operations += reverse_rotate(head_a, head_b, B);
		if (x == WRITE_INST)
			ft_putendl_fd("rrb", 1);
	}
	return (operations);
}

static int	a_up_b_down(t_node **head_a, t_node **head_b, t_node *node, int x)
{
	int		operations;

	operations = 0;
	while ((*head_a)->rank != node->partner->rank)
	{
		operations += rotate(head_a, head_b, A);
		if (x == WRITE_INST)
			ft_putendl_fd("ra", 1);
	}
	while ((*head_b)->rank != node->rank)
	{
		operations += reverse_rotate(head_a, head_b, B);
		if (x == WRITE_INST)
			ft_putendl_fd("rrb", 1);
	}
	return (operations);
}

static int	a_down_b_up(t_node **head_a, t_node **head_b, t_node *node, int x)
{
	int		operations;

	operations = 0;
	while ((*head_a)->rank != node->partner->rank)
	{
		operations += reverse_rotate(head_a, head_b, A);
		if (x == WRITE_INST)
			ft_putendl_fd("rra", 1);
	}
	while ((*head_b)->rank != node->rank)
	{
		operations += rotate(head_a, head_b, B);
		if (x == WRITE_INST)
			ft_putendl_fd("rb", 1);
	}
	return (operations);
}

int	push_best_node(t_node *best_node, t_node **head_a, t_node **head_b, int x)
{
	int	ops;

	ops = 0;
	if (best_node->method_for_push == BOTHUP)
		ops += r_up(head_a, head_b, best_node, x);
	if (best_node->method_for_push == BOTHDOWN)
		ops += rr_down(head_a, head_b, best_node, x);
	if (best_node->method_for_push == ADOWNBUP)
		ops += a_down_b_up(head_a, head_b, best_node, x);
	if (best_node->method_for_push == AUPBDOWN)
		ops += a_up_b_down(head_a, head_b, best_node, x);
	ops += push(PUSH_A, head_a, head_b);
	if (x == WRITE_INST)
		ft_putendl_fd("pa", 1);
	return (ops);
}
