/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 22:01:26 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/08/03 22:28:16 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* new->next =lst this means "look inside the NEW element and set the NEXT
pointer to the FIRST(*) element of the list lst"
we want to change the pointer of the first element to the NEW element(*lst = new)
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
