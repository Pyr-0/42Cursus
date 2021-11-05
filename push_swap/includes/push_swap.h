/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 01:24:41 by mrojas-e          #+#    #+#             */
/*   Updated: 2021/11/02 23:16:39 by mrojas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//====INCLUDES====//

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdbool.h>

//====DEFINES====//

# define ERROR -1
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

//==== STRUCTS ====//

typedef struct s_Ouroboros{
	int					rank;
	int					data;
	struct s_Ouroboros	*next;
	struct s_Ouroboros	*previous;
}t_Ouroboros;

// typedef struct s_Stack{
// 	struct t_Ouroboros	*head;
// 	struct t_Ouroboros	*tail;
// }t_Stack;

//=============== LIST MANAGEMENT =============//

int		ft_create_list(t_Ouroboros **snake_head, char **argv);
void	Print_list(t_Ouroboros *a, t_Ouroboros *b);
int		ft_list_max_is(t_Ouroboros **snake_head);
int		ft_is_sorted(t_Ouroboros **snake_head);
int		ft_list_len(t_Ouroboros **snake_head);

//=============== ALGORITHM =============//

void	ft_sort_2(t_Ouroboros **snake_head, t_Ouroboros *a);
void	ft_sort_3(t_Ouroboros **snake_head);
void	ft_sort_3_1(t_Ouroboros **snake_head, t_Ouroboros *a, t_Ouroboros *b, t_Ouroboros *c);

//=================== OPERATIONS =============//

t_Ouroboros	*ft_pop(t_Ouroboros **current, int x);
void	ft_swap(t_Ouroboros **snake_head);
void	ft_swap_A(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b);
void	ft_swap_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b);
void	ft_swap_both(t_Ouroboros **a, t_Ouroboros **b);
void	ft_push(t_Ouroboros **snake_head, t_Ouroboros *new_node);
void	ft_push_A(t_Ouroboros **a, t_Ouroboros **b);
void	ft_push_B(t_Ouroboros **a, t_Ouroboros **b);
void	ft_rotate(t_Ouroboros **snake_head);
void	ft_rotate_A(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b);
void	ft_rotate_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b);
void	ft_rotate_both(t_Ouroboros **a, t_Ouroboros **b);
void	ft_reverse_rotate(t_Ouroboros **snake_head);
void	ft_RR_A(t_Ouroboros **a, __attribute__ ((unused)) t_Ouroboros **b);
void	ft_RR_B(__attribute__ ((unused)) t_Ouroboros **a, t_Ouroboros **b);
void	ft_RR_both(t_Ouroboros **a, t_Ouroboros **b);

//===== ERROR HANDLING AND FREE MEMORY ====//

int		ft_error(t_Ouroboros **snake_head, char **input);
void	ft_free_list(t_Ouroboros **snake_head);
int		ft_free_array(char **input);
int		ft_check_doubles(t_Ouroboros **snake_head);
int		ft_is_int(char **input);

#endif
