/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:33:00 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/11/01 16:51:02 by mrojas-e         ###   ########.fr       */
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
	t_Ouroboros	*stack_a;
	t_Ouroboros	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = 0;
	stack_a = 0;
	if (ft_create_list(&stack_a, argv) == ERROR)
		return (ERROR);
	ft_is_sorted(&stack_a);
	Print_list(stack_a, stack_b);
	ft_sort_3(&stack_a);
	Print_list(stack_a, stack_b);
	ft_is_sorted(&stack_a);

/*This is the Example from the PDF*/
/*_____________________*/

	// Print_list(stack_a, stack_b);
	// ft_push_B(&stack_a, &stack_b);
	// Print_list(stack_a, stack_b);
	// ft_push_B(&stack_a, &stack_b);
	// Print_list(stack_a, stack_b);
	// ft_push_B(&stack_a, &stack_b);
	// Print_list(stack_a, stack_b);
	// ft_rotate_both(&stack_a, &stack_b);
	// ft_RR_both(&stack_a, &stack_b);
	// Print_list(stack_a, stack_b);
	// ft_swap_A(&stack_a, &stack_b);
	// Print_list(stack_a, stack_b);
	// ft_push_A(&stack_a, &stack_b);
	// Print_list(stack_a, stack_b);
	// ft_push_A(&stack_a, &stack_b);
	// Print_list(stack_a, stack_b);
	// ft_push_A(&stack_a, &stack_b);
	// Print_list(stack_a, stack_b);
	ft_free_list(&stack_a);
	ft_free_list(&stack_b);
	stack_a = NULL;
	stack_b = NULL;
	// system("leaks push_swap");
}
