/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 13:29:19 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/07/31 22:22:15 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = ft_calloc(sizeof (char), (len + 1));
	if (!str || !s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	else
	{
		ft_strlcpy(str, s + start, len + 1);
		return (str);
	}
}


/* 
int	main(void)
{
	const char str[] = "Hello World";
	printf("%s", ft_substr(str, 6, 5));
}
 */
