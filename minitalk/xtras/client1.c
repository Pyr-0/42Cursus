/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:19:48 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/09/16 23:28:13 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str);

int	error_handler(int argc)
{
	if (argc > 3)
	{
		write(1, "Wrong input", 11);
		return (-1);
	}
	if (argc <= 1)
	{
		write(1, "one argument missing", 20);
		return (-1);
	}
	return (1);
}

void	handle_sigusr1(int sig)
{
	sig = 0;
}
void	send()
{
	
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	c;
	int	j;
	int	send;
	int	received;
	int	x;

	received = 0;
	send = 0;
	signal(SIGUSR1, handle_sigusr1);
	if (error_handler(argc) == -1)
		return (0);
	pid = ft_atoi(argv[1]);
	j = 0;
	while (argv[2][j])
	{
		x = 7;
		c = argv[2][j];
		while(x >= 0)
		{
			usleep(10);
			if (c & (1 << x))
				kill(pid, SIGUSR2);
				// printf("1");
			else
				kill(pid, SIGUSR1);
				// printf("0");
			send++;
			pause();
			received++;
			x--;
		}
		j++;
		printf("\n");
	}
	printf ("received =  %d\nsend = %d\n", received, send);
	return (0);
}
