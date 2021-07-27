/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:23:31 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/07/23 11:15:36 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			counter;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (string1[counter] != string2[counter])
			return (string1[counter] - string2[counter]);
		counter++;
	}
	return (0);
}

/*
int main(void)
{
	char s1[42] = "she matters";
	char s2[42] = "she doesn't think it matters";

	printf("The result of ma' function is: %d\n", ft_memcmp(s1, s2, 3) );
	printf("The original functiocn does this too :): %d \n", memcmp(s1, s2, 3));
	return (0);
}
*/