/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 12:45:37 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/08/01 20:16:07 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

	/* this is the part of the function that brings us to the end of the string 
	in order to count backwards*/
char	*ft_strrchr(const char *s, int c)
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
			ptr_return = ((char *)(s + i));
			return (ptr_return);
		}
		i--;
	}
	return (0);
}

/*int	main()
{
	char	*str;
	str =  "Yo wut upY bruhhh!";

	printf("Before the funk is = %s \n", str);
	printf("After the funk is = %s \n", ft_strrchr(str, 'Y'));
	printf("The original funk is = %s \n", strrchr(str, 'Y'));
	printf("222After the funk is = %s \n", ft_strrchr("bonjour", 'b'));
	return(0);	
}*/
