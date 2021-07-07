/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:33:51 by mstrantz          #+#    #+#             */
/*   Updated: 2021/07/07 21:05:12 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!src && !dst)
		return (NULL);
	if (src < dst)
	{
		i = len;
		while (i)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

int main(void)
{
	char str[42] = "Milton WANTS TO TEST SHIT";
	
	printf("%s\n",str);
	printf("changed string : %s\n",ft_memmove(str + 5, str, 7));
	char str2[42] = "Milton WANTS TO TEST SHIT";
	printf("Original changed string : %s\n",ft_memmove(str2 + 5, str2, 7));
	return(0);
}