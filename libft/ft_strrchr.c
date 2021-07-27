/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satori <satori@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:27:12 by satori            #+#    #+#             */
/*   Updated: 2021/07/25 19:33:16 by satori           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
	/* this is the part of the function that brings us to the end of the string 
	in order to count backwards*/
{
	char	*ptr_return;
	int		i;

	ptr_return = NULL;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
		{
			ptr_return = &((char *) s)[i];
			return (ptr_return);
		}
		i--;
	}
	return (ptr_return);
}

/*int	main()
{
	char	*str;
	str =  "Yo wut up bruhhh!";

	printf("Before the funk is = %s \n", str);
	printf("After the funk is = %s \n", ft_strrchr(str, 'Y'));
	printf("The original funk is = %s \n", strrchr(str, 'Y'));
	return(0);	
}
*/
