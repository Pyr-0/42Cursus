/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:38:40 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/11/02 23:30:45 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_list_len(t_Ouroboros **snake_head)
{
	t_Ouroboros	*current;
	int			len;

	len = 1;
	current = *snake_head;
	ft_rotate(&current);
	while (current != *snake_head)
	{
		len++;
		current = current->next;
	}
	return (len);
}

int	ft_list_max_is(t_Ouroboros **snake_head)
{
	t_Ouroboros	*current;
	int			max;
	int			position;

	position = 0;
	current = *snake_head;
	max = current->data;
	current = current->next;
	while (current != *snake_head)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
		position++;
	}
	return (max);
}

int	ft_list_min_is(t_Ouroboros **snake_head)
{
	t_Ouroboros	*current;
	int			min;
	
	current = *snake_head;
	min = current->data;
	current = current->next;
	while (current != *snake_head)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}


int	ft_is_sorted(t_Ouroboros **snake_head)
{
	t_Ouroboros	*current;

	current = *snake_head;
	while (1)
	{
		if (current->next == *snake_head)
			break ;
		if (current->data > current->next->data)
			return (0);
		ft_rotate(&current);
	}
	printf("its sorted\n");
	return (1);
}

void	ft_sort_3(t_Ouroboros **snake_head)
{
	t_Ouroboros	*a;
	t_Ouroboros	*b;
	t_Ouroboros	*c;

	a = (*snake_head);
	b = (*snake_head)->next;
	c = (*snake_head)->previous;
	if (ft_list_len (&a) == 2)
		ft_sort_2(snake_head, a);
	if (ft_list_len (&a) == 3)
		ft_sort_3_1(snake_head, a, b, c);
}

void	ft_sort_2(t_Ouroboros **snake_head, t_Ouroboros *a)
{
	if (ft_is_sorted(snake_head))
		return ;
	else
		ft_swap_A(&a, NULL);
}

void	ft_sort_3_1(t_Ouroboros **snake_head, t_Ouroboros *a, t_Ouroboros *b, t_Ouroboros *c)
{
	if		(ft_is_sorted(snake_head))
		return ;
	else if (a->data < c->data && b->data < a->data && b ->data < c->data)
		ft_swap_A(&a, NULL);
	else if (b->data < a->data && c->data < a->data && c->data < b->data)
	{
		ft_swap_A(&a, NULL);
		ft_RR_A(snake_head, NULL);
	}	
	else if (b->data < a->data && b->data < c->data && c->data < a->data)
		ft_rotate_A(snake_head, NULL);
	else if (a->data < b->data && a->data < c->data && a->data < b->data)
	{
		ft_swap_A(&a, NULL);
		ft_rotate_A(snake_head, NULL);
	}
	else if (a->data < b->data && c->data < a->data && c->data < b->data)
		ft_RR_A(snake_head, NULL);
}

void	sort_5(t_Ouroboros **snake_head)
{
	t_Ouroboros *stack_a;
	t_Ouroboros *stack_b;
	
	stack_a = *snake_head;
	stack_b = NULL;
	if 	(ft_is_sorted(snake_head))
		return ;
	ft_list_max_is
	ft_push_A()
}

