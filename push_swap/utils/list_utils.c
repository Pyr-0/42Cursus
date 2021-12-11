/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:01:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/12/02 19:14:16 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*====Extra functions====*/

void	Print_list( t_Ouroboros *a, t_Ouroboros *b)
{
	t_Ouroboros	*temp;
	t_Ouroboros	*temp_b;

	temp = a;
	temp_b = b;
	printf(YELLOW"%10s |%8s\n", "Stack A", "Stack B");
	printf(YELLOW"%23s\n", "-------------------");
	if (temp)
	{
		printf(CYAN"%6i", temp->data);
		printf(RED"%4i", temp->rank);
	}
	else
		printf("          ");
	if (temp_b)
	{	printf(CYAN"%7i", temp_b->data);
		printf(RED"%4i", temp_b->rank);}
	printf("\n");
	if (temp)
		temp = temp->next;
	if (temp_b)
		temp_b = temp_b->next;
	while (1)
	{
		if (temp != a && temp)
		{
			printf(CYAN"%6i"RESET, temp->data);
			printf(RED"%4i"RESET, temp->rank);
		}
		else
			printf("          ");
		if (temp_b != b && temp_b)
		{
			printf(CYAN"%7i"RESET, temp_b->data);
			printf(RED"%4i"RESET, temp_b->rank);
		}
		printf("\n");
		if (temp != a)
			temp = temp->next;
		if (temp_b != b)
			temp_b = temp_b->next;
		if (temp == a && temp_b == b)
			break ;
	}
	printf("\n");
}

int	ft_list_len(t_Ouroboros **snake_head)
{
	t_Ouroboros	*current;
	int			len;

	if (*snake_head == NULL)
		return (0);
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

t_Ouroboros	*ft_list_min_is(t_Ouroboros **snake_head)
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
	return(current);
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

