/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 23:19:48 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/10/18 19:23:44 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr_server(int sig)
{
	sig = 0;
}

int	error_handler(int argc, char *argv[])
{
	if (argc != 3)
	{
		if (argc > 3)
			ft_printf("Too many Arguments\n");
		else
		{
			ft_printf("Wrong input!\n");
			ft_printf("Enter the file name, the Server's PID");
			ft_printf(" and the signal you want to send\n");
		}
		return (-1);
	}
	if (atoi(argv[1]) == 0)
	{
		ft_printf("Illegal PID!\n");
		return (-1);
	}
	return (1);
}

void	ft_init_vars(char **argv, t_vars *vars)
{
	vars->pid = ft_atoi(argv[1]);
	vars->c = 0;
	vars->j = 0;
	vars->send = 0;
	vars->back = 0;
	vars->x = 0;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (error_handler(argc, argv) == -1)
		return (0);
	ft_init_vars(argv, &vars);
	signal(SIGUSR1, handle_sigusr_server);
	while (argv[2][vars.j])
	{
		vars.x = 7;
		vars.c = argv[2][vars.j++];
		while (vars.x >= 0)
		{
			usleep(80);
			if (vars.c & (1 << vars.x))
				kill(vars.pid, SIGUSR2);
			else
				kill(vars.pid, SIGUSR1);
			pause();
			vars.x--;
		}
		vars.send++;
		vars.back++;
	}
	ft_printf ("\nBytes received = %d\nBytes sent = %d\n", vars.back, vars.send);
}
