/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:54:47 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/07/10 18:55:50 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char  *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	src_len;

	src_len = ft_strlen(src); 
	counter = 0;

	if (!dst || !src)
		return (0);
	while ((counter + 1) < dstsize && src[counter] != 0) // this is checking if there is a NULL terminator at the source and if it is then its over 
	{
		dst[counter] = src[counter];
		counter++;
	}
	/* there is another case when there is no space for shait (when dst_size = 0)*/
	if (dstsize)
		dst[counter] = 0; // we haver to add the nulll terminator to the END of the destination >.<!! 
	return (src_len);
}
