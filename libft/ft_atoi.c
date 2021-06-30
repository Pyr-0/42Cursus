/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:28:26 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/06/30 18:43:24 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isspace(char c)

{
	if (c == ' ' || c == '\f' || c == '\v' || c == '\n' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi (const char *str)

{
	int		sign;
	int		counter;
	long	result;

	sign = 1;
	result = 0;
	counter = 0;
	while (isspace (str[counter]))
		counter ++;
	if (str[counter] == '+')
		counter++;
	else if (str[counter] == '-')
	{
		sign = -1;
		counter++;
	}
	while (ft_isdigit(str[counter]))
	{
		result = result * 10 + (str[counter] - '0');
		counter++;
	}
	return (result * sign);
}
