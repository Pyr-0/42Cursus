/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:13:14 by eozben            #+#    #+#             */
/*   Updated: 2021/11/01 19:33:18 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	rm_node_cdll(t_node **head, t_node *node)
{
	t_node	*control;

	if (head == NULL || *head == NULL || node == NULL)
		return (ERROR);
	if (*head != node)
	{
		control = (*head)->next;
		while (control != node && control != (*head))
			control = control->next;
		if (control == *head)
			return (ERROR);
	}
	detach_node(head, node);
	free(node);
	node = NULL;
	return (0);
}

void	free_cdll(t_node **head)
{
	if (head == NULL || *head == NULL)
		return ;
	while (*head != NULL)
		rm_node_cdll(head, *head);
}

void	freearray(char **arr)
{
	int	i;

	i = 0;
	if (arr[i])
	{
		while (arr[i])
			free(arr[i++]);
	}
	if (arr)
		free(arr);
}

int	error_cdll(t_node **head, char **input)
{
	if (input != NULL)
		freearray(input);
	ft_putendl_fd("Error", 2);
	free_cdll(head);
	exit(1);
	return (ERROR);
}

int	error_cdll2(t_node **head, t_node **head_b, char *inst)
{
	ft_putendl_fd("Error", 2);
	free(inst);
	free_cdll(head);
	free_cdll(head_b);
	exit(1);
	return (ERROR);
}
