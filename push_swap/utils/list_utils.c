/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 23:01:03 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/10/31 23:26:49 by mrojas-e         ###   ########.fr       */
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
