/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:33:55 by mstrantz          #+#    #+#             */
/*   Updated: 2021/07/09 18:47:07 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1_c;
	unsigned char	*str2_c;

	str1_c = (unsigned char *)str1;
	str2_c = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (str1_c[i] != str2_c[i])
			return (str1_c[i] - str2_c[i]);
			i++;
	}
	return (0);
}
