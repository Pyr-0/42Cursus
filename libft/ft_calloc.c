/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:56:14 by satori            #+#    #+#             */
/*   Updated: 2021/07/25 19:34:01 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	counter;
	size_t	size_in_bytes;

	counter = 0;
	size_in_bytes = nitems * size;
	ptr = (char *)malloc(size_in_bytes);
	if (ptr == NULL)
		return (ptr);
	while (counter < size_in_bytes)
	{
		ptr[counter] = 0;
		counter++;
	}
	return (ptr);
}
