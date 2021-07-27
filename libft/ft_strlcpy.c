/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:54:47 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/07/23 11:53:04 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*line 25 : This is checking if there is a NULL terminator at the source and if
it is then its over */
/*line 30 : there is another case when there is no space for shait
(when dst_size=0)*/
/*we haver to add the nulll terminator to the END of the destination >.<!*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	src_len;

	src_len = ft_strlen(src);
	counter = 0;
	if (!dst || !src)
		return (0);
	while ((counter + 1) < dstsize && src[counter] != 0)
	{
		dst[counter] = src[counter];
		counter++;
	}
	if (dstsize)
		dst[counter] = 0;
	return (src_len);
}
