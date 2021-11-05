/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:23:55 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/10/31 23:52:01 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*====Reverse Rotate Functions====*/

void	ft_reverse_rotate(t_Ouroboros **snake_head)
{
	*snake_head = (*snake_head)->previous;
	return ;
}

void	ft_RR_A(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b)
{
	ft_reverse_rotate(a);
	write(1, CYAN, 7);
	write(1, "rra\n", 4);
}

void	ft_RR_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_reverse_rotate(b);
	write(1, CYAN, 7);
	write(1, "rrb\n", 4);
}

void	ft_RR_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	write(1, CYAN, 7);
	write(1, "rrr\n", 4);
}
