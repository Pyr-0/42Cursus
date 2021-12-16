/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:51:12 by eozben            #+#    #+#             */
/*   Updated: 2021/11/01 19:37:13 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_for_hold(t_node **head_a)
{
	t_node	*current;

	current = *head_a;
	while (1)
	{
		if (current->hold == 0 || current->swap == 1)
			return (1);
		current = current->next;
		if (current == *head_a)
			break ;
	}
	return (0);
}

void	ranker(t_node **head)
{
	unsigned int	rank;
	t_node			*current;
	t_node			*check_smaller;

	current = *head;
	while (1)
	{
		rank = 0;
		check_smaller = *head;
		while (1)
		{
			check_smaller = check_smaller->next;
			if (check_smaller->nb < current->nb)
				rank++;
			if (check_smaller == *head)
				break ;
		}
		current->rank = rank;
		current = current->next;
		if (current == *head)
			break ;
	}
}

int	check_doubles(t_node **head)
{
	t_node	*current;
	t_node	*current2;

	current = *head;
	while (1)
	{
		current2 = current;
		while (1)
		{
			current2 = current2->next;
			if (current2 == current)
				break ;
			if (current->nb == current2->nb)
				return (ERROR);
		}
		current = current->next;
		if (current == *head)
			break ;
	}
	return (0);
}

int	create_cdll(char **argv, t_node **head)
{
	char	**input;
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		input = ft_split(argv[i], ' ');
		if (!input)
			return (error_cdll(head, NULL));
		j = 0;
		while (input[j])
		{
			if (add_element(input[j], head) == -1 || check_doubles(head) == -1)
				return (error_cdll(head, input));
			j++;
		}
		freearray(input);
	}
	return (0);
}

void	sort(t_node **head_a, t_node **head_b)
{
	t_node			*best_node;
	int				ops;

	ops = 0;
	best_node = NULL;
	ranker(head_a);
	get_ordinal_stack(head_a, &best_node, 1);
	hold_ordinal_nums(head_a, head_b, WRITE_INST);
	ops += sort_stack_b(head_a, head_b, WRITE_INST);
	ops += sort_stack_a(head_a, WRITE_INST);
}
