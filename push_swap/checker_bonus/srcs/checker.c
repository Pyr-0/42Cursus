/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:30:56 by eozben            #+#    #+#             */
/*   Updated: 2021/11/01 19:36:28 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	compare_inst(t_node **head_a, t_node **head_b, char *inst)
{
	if (ft_strcmp(inst, "sa\n"))
		swap_top(head_a);
	else if (ft_strcmp(inst, "sb\n"))
		swap_top(head_b);
	else if (ft_strcmp(inst, "ss\n"))
		swap_both_tops(head_a, head_b);
	else if (ft_strcmp(inst, "ra\n"))
		rotate(head_a, head_b, A);
	else if (ft_strcmp(inst, "rb\n"))
		rotate(head_a, head_b, B);
	else if (ft_strcmp(inst, "rr\n"))
		rotate_both(head_a, head_b);
	else if (ft_strcmp(inst, "rra\n"))
		reverse_rotate(head_a, head_b, A);
	else if (ft_strcmp(inst, "rrb\n"))
		reverse_rotate(head_a, head_b, B);
	else if (ft_strcmp(inst, "rrr\n"))
		reverse_rotate_both(head_a, head_b);
	else if (ft_strcmp(inst, "pa\n"))
		push(A, head_a, head_b);
	else if (ft_strcmp(inst, "pb\n"))
		push(B, head_a, head_b);
	else
		error_cdll2(head_a, head_b, inst);
	free(inst);
}

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;
	char	*instruction;

	if (argc < 2)
		return (0);
	if (create_cdll(argv, &head_a) == -1)
		return (0);
	ranker(&head_a);
	head_b = NULL;
	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		compare_inst(&head_a, &head_b, instruction);
		instruction = NULL;
	}
	if (check_if_sorted(&head_a, &head_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_cdll(&head_a);
	free_cdll(&head_b);
	return (0);
}
