/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:54:32 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/07/08 19:42:58 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s; //Defining the variable that will be typecasted
	size_t			counter; //This counter(s) need to be type size_t because we need to move in the counter n positions in a positive(+) direction.

	char_s = (unsigned char *)s; // this is the Svenja way of type casting the shit out of a variable. butt! we could also type cast like this ((unsigned char *) dst) and use it every time we need to call it.
	counter = 0;

	while(counter < n) // We check the amount of bytes that we give it to check (: its not very deep stuf man ;)
	{
		if (char_s[counter] == (unsigned char)c)
			return(&char_s[counter]); // We need to return a pointer to the correct location, and we use referencing (&) to do so ;)
		counter++;
	} 
	return (NULL);
}

int main(void)
{
	char *s = "lets see if that works :)";			// we could use the array system to gicve the value to the string or also like here, the pointer way of life :D

	printf("The input is: %s\n", s);   // we declaire already the values from the funnction memchar
	printf("My output is : %s\n", ft_memchr(s, 'a', 100));
	printf(" The original memchr output is : %s\n", memchr(s, 'a', 100));			//we call the original function to acvtion in order to control our own function
	return (0);
}

//THIS IS DOPE, Svenja's Swag! 