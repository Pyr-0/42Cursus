/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 23:05:54 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/08/03 23:28:17 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* there is a special case if the list is completely empty we want
to add the NEW element to the start*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
	new->next = NULL;
}
