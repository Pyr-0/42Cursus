/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:33:00 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/10/28 00:59:52 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h> 

#include "../includes/push_swap.h"

void	ft_create_new_node(t_Ouroboros **snake_head, int input)
{
	t_Ouroboros	*new_node;

	new_node = malloc(sizeof(t_Ouroboros));
	if (new_node == NULL)
		return ;
	new_node->data = input;
	ft_push(snake_head, new_node);
	ft_rotate(snake_head);
}

int	ft_create_list(t_Ouroboros **snake_head, char **argv)
{
	int		i;
	int		j;
	char	**input;

	i = 1;
	while (argv[i])
	{	
		input = ft_split(argv[i], ' ');
		if (ft_is_int(input) == ERROR)
			return (ft_error(NULL, input));
		j = 0;
		while (input[j])
			ft_create_new_node(snake_head, ft_atoi(input[j++]));
		ft_free_array(input);
		i++;
	}
	if (ft_check_doubles(snake_head) == ERROR)
		return (ft_error(snake_head, NULL));
	return (0);
}

int	main(int argc, char **argv)
{
	t_Ouroboros	*a;
	t_Ouroboros	*b;

	if (argc < 2)
		return (0);
	b = 0;
	a = 0;
	if (ft_create_list(&a, argv) == ERROR)
		return (ERROR);
/*This is the Example from the PDF*/
/*_____________________*/

	// Print_list(a, b);
	// ft_swap_A(&a, &b);
	// Print_list(a, b);
	// ft_push_B(&a, &b);
	// Print_list(a, b);
	// ft_push_B(&a, &b);
	// Print_list(a, b);
	// ft_push_B(&a, &b);
	// Print_list(a, b);
	// ft_rotate_both(&a, &b);
	// ft_RR_both(&a, &b);
	// Print_list(a, b);
	// ft_swap_A(&a, &b);
	// Print_list(a, b);
	// ft_push_A(&a, &b);
	// Print_list(a, b);
	// ft_push_A(&a, &b);
	// Print_list(a, b);
	// ft_push_A(&a, &b);
	Print_list(a, b);
	ft_free_list(&a);
	ft_free_list(&b);
	a = NULL;
	b = NULL;
	system("leaks push_swap");
}
