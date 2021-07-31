/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:44:16 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/07/28 15:28:27 by mrojas-e         ###   ########.fr       */
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

	if (dst == 0 && src == 0)
		return (0);
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
