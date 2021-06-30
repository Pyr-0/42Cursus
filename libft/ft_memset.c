/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:36:31 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/06/24 16:04:40 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)

{
	size_t	counter;

	counter = 0;
	while (counter < len)
	{
		((unsigned char *) b)[counter] = (unsigned char) c;
		counter++;
	}
	return (b);
}
