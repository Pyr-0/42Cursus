/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:47:07 by eozben            #+#    #+#             */
/*   Updated: 2021/11/01 19:37:43 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR -1
# define PUSH_A 0
# define PUSH_B 1
# define A 0
# define B 1
# define BOTHUP 0
# define BOTHDOWN 1 
# define ADOWNBUP 2
# define AUPBDOWN 3
# define WRITE_INST 69

typedef struct s_node
{
	int				nb;
	unsigned int	rank;
	unsigned int	hold;
	int				actions_for_push;
	int				method_for_push;
	int				pos;
	int				swap;
	struct s_node	*partner;
	struct s_node	*next;
	struct s_node	*previous;
}			t_node;

int				add_element(char *number, t_node **head);
int				check_doubles(t_node **head);
void			freearray(char **arr);
void			free_cdll(t_node **head);
void			detach_node(t_node **head, t_node *node);
void			attach_node(t_node **head, t_node *newnode);
int				rotate_both(t_node **head_a, t_node **head_b);
int				rotate(t_node **head_a, t_node **head_b, int x);
int				reverse_rotate_both(t_node **head_a, t_node **head_b);
int				reverse_rotate(t_node **head_a, t_node **head_b, int x);
int				swap_top(t_node **head);
int				swap_both_tops(t_node **head_a, t_node **head_b);
int				push(int x, t_node **head_a, t_node **head_b);
t_node			*cdll_append(t_node **head);
int				push_best_node(t_node *best_node, t_node **head_a,
					t_node **head_b, int x);
t_node			*copy_cdll(t_node **head);
unsigned int	get_ordinal_stack(t_node **head_a, t_node **best_node,
					unsigned int gap);
void			hold_ordinal_nums(t_node **head_a, t_node **head_b, int x);
t_node			*find_partner_node(t_node *head_a, t_node *node_b);
int				find_min_moves(t_node *node, t_node **head_a, t_node **head_b);
int				sort_stack_b(t_node **head_a, t_node **head_b, int x);
int				sort_stack_a(t_node **head_a, int x);
int				get_stack_size(t_node *head);
int				check_for_hold(t_node **head_a);
int				create_cdll(char **argv, t_node **head);
void			ranker(t_node **head);
int				check_if_sorted(t_node **head_a, t_node **head_b);
int				error_cdll2(t_node **head, t_node **head_b, char *inst);
int				error_cdll(t_node **head, char **input);

#endif