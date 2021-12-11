/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:38:40 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/02 19:57:48 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	ft_get_position(t_Ouroboros **snake_head)
{
	t_Ouroboros *current;
	int			i;

	i = 0;
	current = *snake_head;
	while (1)
	{
		current->position = i++;
		current = current->next;
		if (current == *snake_head)
			break ;
	}
}

/* void	sort_stack(t_Ouroboros **snake_head)
{
	t_Ouroboros	*min_rank;

	ft_get_position(*snake_head);
	min_rank = ft_list_min_is(*snake_head);
	min_rank->position
	while (ft_is_sorted(snake_head) == 0)
} */

void	ft_sort_2(t_Ouroboros **snake_head, t_Ouroboros *a)
{
	if (ft_is_sorted(snake_head))
		return ;
	else
		ft_swap_A(&a, NULL);
}
void	ft_sort_3(t_Ouroboros **snake_head)
{
	t_Ouroboros	*a;
	t_Ouroboros	*b;
	t_Ouroboros	*c;

	a = (*snake_head);
	b = (*snake_head)->next;
	c = (*snake_head)->previous;
	if (ft_list_len (&a) <= 2)
		return(ft_sort_2(snake_head, a));
	if (ft_list_len (&a) == 3)
		ft_sort_3_1(snake_head, a, b, c);
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

void	ft_sort_4(t_Ouroboros **stack_a, t_Ouroboros **stack_b)
{
	if 	(ft_is_sorted(stack_a))
		return ;
	Print_list(*stack_a, *stack_b);
	ft_push_to_B(stack_a, stack_b);
	ft_sort_3(stack_a);
	Print_list(*stack_a, *stack_b);
	(*stack_b)->partner = find_partner((*stack_a), *stack_b);
	while(1)
	{
		Print_list(*stack_a, *stack_b);
		if (*stack_a == (*stack_b)->partner)
		{
			ft_push_to_A(stack_a, stack_b);
			break ;
		}
		else
			ft_rotate_A(stack_a, stack_b);
	}
	Print_list(*stack_a, *stack_b);
	while((*stack_a)->rank != 0)
	{
		ft_rotate_A(stack_a, stack_b);
		Print_list(*stack_a, *stack_b);
	}
} 

void	ft_sort_5(t_Ouroboros **stack_a, t_Ouroboros **stack_b)
{
	if 	(ft_is_sorted(stack_a))
		return ;
	ft_push_to_B(stack_a, stack_b);
	ft_push_to_B(stack_a, stack_b);
	ft_sort_3(stack_a); 
	while(*stack_b != NULL)
	{
		(*stack_b)->partner = find_partner((*stack_a), *stack_b);
		if (*stack_a == (*stack_b)->partner)
			ft_push_to_A(stack_a, stack_b);
		else
			ft_rotate_A(stack_a, stack_b);
	}
	while((*stack_a)->rank != 0)
	{
		ft_rotate_A(stack_a, stack_b);
	}
}

void	ft_radix_sort(t_Ouroboros **stack_a, t_Ouroboros **stack_b)
{
	int i;
	int elements_processed;
	int elements_total;

	i = 0;
	elements_total = ft_list_len(stack_a);
	while(i < 32)
	{
		if (/* column i DOES NOT contain only zeroes (or only ones) */ 1)
		{
			elements_processed = 0;
			while(elements_processed < elements_total)
			{
				if(((*stack_a)->inverse_rank & (1 << i)))
					ft_push_to_B(stack_a, stack_b);
				else
					ft_rotate_A(stack_a, stack_b);
				elements_processed ++;
			}
			while (ft_list_len(stack_b) != 0)
				ft_push_to_A(stack_a, stack_b);
		}
		i++;
	}
}

void	choose_algo(t_Ouroboros **stack_a,  t_Ouroboros **stack_b,int len)
{
	if (len <= 3)
		ft_sort_3(stack_a);
	else if (len == 4)
		ft_sort_4(stack_a, stack_b);
	else if (len == 5)
		ft_sort_5(stack_a, stack_b);
	else
		ft_radix_sort(stack_a, stack_b);
}

