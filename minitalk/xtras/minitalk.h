/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:39:04 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/09/20 13:19:34 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/* **CLIENT** */

typedef struct s_vars {
	int	pid;
	int	c;
	int	j;
	int	send;
	int	received;
	int	x;
}	t_vars;

int	ft_atoi(const char *str);
int	error_handler(int argc);
void	handle_sigusr1(int sig, siginfo_t *info, void *useless);
void	ft_init_vars(char **argv, t_vars *vars);
void	handle_sigusr_server(int sig);
void	response_count(t_vars *vars);


/* **SERVER** */


#endif
