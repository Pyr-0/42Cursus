/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:13:25 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/07/07 20:44:59 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

void	*ft_memcpy(void * dst, const void * src, size_t n)

{
	
	size_t	counter;

	if(dst + n >= src && dst <= src + n -1)
	{
		return (0);
	}
	counter = 0;
	while (counter < n)
	{
		((unsigned char *) dst)[counter] = ((unsigned char *) src)[counter];
		counter++;
	}
	return (dst);
}
int main(void)
{
	char str[42] = "Milton";
	char str2[42] = "Rojas";
	
	printf("%s\n",str);
	printf("changed string : %s\n",ft_memcpy(str, str2, 3));
	char str3[42] = "Milton";
	char str4[42] = "Rojas";
	printf("Original changed string : %s\n",memcpy(str3, str4, 3));
	return(0);
}