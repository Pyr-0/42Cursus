/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 19:43:07 by satori            #+#    #+#             */
/*   Updated: 2021/07/26 00:19:01 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);

/*REMEMBER: we need to substract one from the len due
to the offseth of the string! */
char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	counter;
	size_t	len_of_small;
	char	*big_iter;

	len_of_small = ft_strlen(small);
	counter = 0;
	if (len_of_small == 0)
		return ((char *)big);
	while (big[counter] != '\0' && counter + (len_of_small - 1) < len)
	{
		big_iter = &((char *)big)[counter];
		if (ft_memcmp(big_iter, small, len_of_small) == 0)
			return (big_iter);
		counter++;
	}
	return (NULL);
}

/*int	main()
{
	char	big[] = "Hello , how you doin'";
	char	small[] = "how";

	printf("Before the funk is = %s \n", big);
	printf("After the funk is = %s \n", ft_strnstr(big, small, 11));
	printf("The original funk is = %s \n", strstr(big, small));
	return(0);
}
*/
