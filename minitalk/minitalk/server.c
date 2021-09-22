/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:33:02 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/09/21 21:40:00 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr1(int my_signal, siginfo_t *info,
					__attribute__ ((unused)) void *useless)
{
	static char	received_value = 0;
	static int	bits = 0;

	if (my_signal == SIGUSR2)
		received_value = received_value | 1;
	bits++;
	if (bits == 8)
	{
		write(1, &received_value, 1);
		bits = 0;
		received_value = 0;
	}
	else
		received_value = received_value << 1;
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa_act;

	sa_act.sa_flags = SA_SIGINFO;
	sa_act.sa_sigaction = &handle_sigusr1;
	sigaction(SIGUSR1, &sa_act, NULL);
	sigaction(SIGUSR2, &sa_act, NULL);
	ft_printf ("Hello, I am the Server and I run with the PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
