/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:20:24 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/06/24 15:03:58 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>
#include <string.h>

// int test_ft_memset();
// int test_ft_isprint();
// int test_ft_isascii();
int	test_ft_atoi();
int main()
{
	// printf("ft_memset:	%d\n", test_ft_memset());
	// test_ft_isprint();
	// test_ft_isascii();
	test_ft_atoi();

	return(0);
}

/*int test_ft_memset()
{
	char str[] = "hello test number 1\n";
	ft_memset (str + 6, 'h' , 6);
	
	if (strcmp (str, "hello hhhhhhumber 1\n")!=0 )
		return (0);
	return (1);
}

int	test_ft_isprint()
{
	int a = '@';
	int b = '\0';

	printf("a= %c can be printed %d\n", a, ft_isprint (a));
	printf("b= %c cannot  be printed %d\n", b, ft_isprint (b));
	return(0);
}

int test_ft_isascii()
{
	int a = '9';
	int b = 5000000;

	printf("ft_isascii:%d\n", test_ft_memset());
	printf("		%c\n", ft_isprint (a));
	printf("		 %d\n",ft_isprint (b));
	return 0;
}*/

int	test_ft_atoi()

{
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("---42"));
	printf("%d\n", ft_atoi("---42b"));
	printf("%d\n", ft_atoi("---42b25"));
	// printf("%d\n", ft_atoi("-2147483648"));

	return(0);
}
