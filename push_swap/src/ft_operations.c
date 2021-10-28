/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:01:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/10/28 15:19:16 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include "../includes/helper.h"

/*====Swap Functions====*/
/* The swap function only changes the top 2 values by
changing the data variable of each node*/

void	ft_swap(t_Ouroboros **stackA_B)
{
	int	temp;

	temp = (*stackA_B)->data;
	(*stackA_B)->data = (*stackA_B)->next->data;
	(*stackA_B)->next->data = temp;
	return ;
}

void	ft_swap_A(t_Ouroboros **a,
		__attribute__ ((unused)) t_Ouroboros **b)
{
	ft_swap(a);
	write(1, CYAN, 7);
	write(1, "sa\n", 3);
}

void	ft_swap_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_swap(b);
	write(1, CYAN, 7);
	write(1, "sb", 2);
}

void	ft_swap_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, CYAN, 7);
	write(1, "ss", 2);
}

/*====Rotate functions====*/

void	ft_rotate(t_Ouroboros **snake_head)
{
	*snake_head = (*snake_head)->next;
	return ;
}

void	ft_rotate_A(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b)
{
	ft_rotate(a);
	write(1, CYAN, 7);
	write(1, "ra"RED, 2);

}

void	ft_rotate_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_rotate(b);
	write(1, CYAN, 7);
	write(1, "rb", 2);
}

void	ft_rotate_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, CYAN, 7);
	write(1, "rr", 2);
}

/*====Reverse Rotate Functions====*/

void	ft_reverse_rotate(t_Ouroboros **adm)
{
	*adm = (*adm)->previous;
	return ;
}
void	ft_RR_A(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b)
{
	ft_reverse_rotate(a);
	write(1, CYAN, 7);
	write(1, "rra", 2);
}
void	ft_RR_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_reverse_rotate(b);
	write(1, CYAN, 7);
	write(1, "rrb", 2);
}
void	ft_RR_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, CYAN, 7);
	write(1, "rrr", 2);
}

/*====Push Functions====*/

void	ft_push(t_Ouroboros **snake_head, t_Ouroboros *new_node)
{
	if (!new_node)
		return ;
	if (*snake_head == NULL)
	{
		new_node->previous = new_node;
		new_node->next = new_node;
		*snake_head = new_node;
	}
	else
	{
		(*snake_head)->previous->next = new_node;
		new_node->previous = (*snake_head)->previous;
		(*snake_head)->previous = new_node;
		new_node->next = *snake_head;
		*snake_head = new_node;
	}
}

void	ft_push_A(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_push(a, ft_pop(b, 0));
	write(1, CYAN, 7);
	write(1, "pa", 2);
}

void	ft_push_B(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_push(b, ft_pop(a , 0));
	write(1, CYAN, 7);
	write(1, "pb", 2);
}

/*====Extra functions====*/
t_Ouroboros	*ft_pop(t_Ouroboros **snake_head, int x)
{
	t_Ouroboros	*temp;

	if (snake_head == NULL || *snake_head == NULL)
		return (NULL);
	temp = *snake_head;
	if (*snake_head == (*snake_head)->previous)
	{	
		if (x == 1)
			free(*snake_head);
		*snake_head = NULL;
		return (temp);
	}
	*snake_head = temp->next;
	(*snake_head)->previous = temp->previous;
	(*snake_head)->previous->next = *snake_head;
	temp->next = temp;
	temp->previous = temp;
	if (x == 1)
		free(temp);
	return (temp);
}

void	Print_list( t_Ouroboros *a, t_Ouroboros *b)
{
	t_Ouroboros	*temp;
	t_Ouroboros	*temp_b;

	temp = a;
	temp_b = b;
	printf(YELLOW"%10s |%8s\n", "Stack A", "Stack B");
	printf(YELLOW"%23s\n", "-------------------");
	if (temp)
		printf(CYAN"%10i", temp->data);
	else
		printf("          ");
	if (temp_b)
		printf(CYAN"%8i", temp_b->data);
	printf("\n");
	if (temp)
		temp = temp->next;
	if (temp_b)
		temp_b = temp_b->next;
	while (1)
	{
		if (temp != a && temp)
			printf(CYAN"%10i", temp->data);
		else
			printf("          ");
		if (temp_b != b && temp_b)
			printf(CYAN"%8i", temp_b->data);
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
