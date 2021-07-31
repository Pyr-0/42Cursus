/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 13:51:57 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/07/28 14:22:13 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == 0 || s2[i] == 0)
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
		i++;
	}
	return (0);
}

/*
int main()
{
	char	s1 [] = "abcde \n";
	char	s2 [] = "abcd \n";
	
	printf("Original string is %s \n" , s1);
	printf("after compare string is %d \n" , ft_strncmp (s1, s2, 5));
	printf("the original string is %d \n" , strncmp (s1, s2, 5));
	return (0);
}
*/