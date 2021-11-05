/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:21:30 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/10/31 23:53:54 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	write(1, "ra\n", 3);
}

void	ft_rotate_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b)
{
	ft_rotate(b);
	write(1, CYAN, 7);
	write(1, "rb\n", 3);
}

void	ft_rotate_both(t_Ouroboros **a, t_Ouroboros **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, CYAN, 7);
	write(1, "rr\n", 3);
}
