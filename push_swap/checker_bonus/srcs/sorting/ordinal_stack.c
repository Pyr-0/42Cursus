/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordinal_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 06:23:08 by mac               #+#    #+#             */
/*   Updated: 2021/11/01 18:30:08 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	clear_swaps(t_node *best_node)
{
	t_node	*current;

	current = best_node->next;
	while (current != best_node)
	{
		if (current->swap == 1)
			current->swap = 0;
		current = current->next;
	}
}

static void	mark_ordinal_nums(t_node *best_node, unsigned int gap)
{
	t_node			*current;
	unsigned int	first_rank;

	current = best_node;
	if (best_node->swap == 1)
		swap_top(&best_node);
	first_rank = current->rank;
	while (1)
	{
		if (current->rank >= first_rank && current->rank <= first_rank + gap)
		{
			current->hold = 1;
			first_rank = current->rank;
		}
		current = current->next;
		if (current == best_node)
			break ;
	}
	if (best_node->swap == 1)
		swap_top(&best_node);
}

static unsigned int	find_ordinal_nums(t_node *current, unsigned int gap,
	t_node **best_node)
{
	t_node				*runner;
	unsigned int		current_rank;
	static unsigned int	latest_streak;
	unsigned int		streak;

	runner = current;
	streak = 1;
	current_rank = runner->rank;
	while (1)
	{
		runner = runner->next;
		if (runner == current)
			break ;
		if (runner->rank > current_rank && runner->rank <= current_rank + gap)
		{
			current_rank = runner->rank;
			streak++;
		}
	}
	if (streak > latest_streak)
	{
		latest_streak = streak;
		*best_node = current;
	}
	return (latest_streak);
}

unsigned int	get_ordinal_stack(t_node **head_a, t_node **best_node,
			unsigned int gap)
{
	t_node			*current;
	unsigned int	l_streak[2];

	current = *head_a;
	while (1)
	{
		l_streak[0] = find_ordinal_nums(current, gap, best_node);
		swap_top(&current);
		l_streak[1] = find_ordinal_nums(current, gap, best_node);
		swap_top(&current);
		if (l_streak[1] > l_streak[0])
			current->swap = 1;
		current = current->next;
		if (current == *head_a)
			break ;
	}
	clear_swaps(*best_node);
	mark_ordinal_nums(*best_node, gap);
	if (l_streak[0] > l_streak[1])
		return (l_streak[0]);
	return (l_streak[1]);
}

void	hold_ordinal_nums(t_node **head_a, t_node **head_b, int x)
{
	t_node	*current;

	current = *head_a;
	while (check_for_hold(head_a))
	{
		if ((*head_a)->swap == 1)
		{
			swap_top(head_a);
			(*head_a)->swap = 0;
			if (x == WRITE_INST)
				ft_putendl_fd("sa", 1);
		}
		else if ((*head_a)->hold == 0)
		{
			push(PUSH_B, head_a, head_b);
			if (x == WRITE_INST)
				ft_putendl_fd("pb", 1);
		}
		else
		{
			rotate(head_a, head_b, A);
			if (x == WRITE_INST)
				ft_putendl_fd("ra", 1);
		}
	}
}
