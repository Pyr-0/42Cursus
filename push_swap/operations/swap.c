/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:20:04 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/10/31 23:20:29 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
