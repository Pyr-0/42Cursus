# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: satori <satori@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 17:50:34 by eozben            #+#    #+#              #
#    Updated: 2021/12/16 22:48:14 by satori           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
INC = -Iincludes
LIB = -L../libft -lft
FLAGS = -o "checker" -Wall -Wextra -Werror

all:$(NAME)

$(NAME):
	@gcc $(FLAGS) srcs/push_swap.c srcs/checker.c srcs/get_next_line.c srcs/get_next_line_utils.c srcs/sorting/ordinal_stack.c srcs/sorting/sort_a.c srcs/sorting/sort_b_utils.c srcs/sorting/sort_b.c srcs/instructions/methods.c srcs/cdll/cdll_utils.c srcs/cdll/cdll_errors.c srcs/instructions/operations.c srcs/instructions/rotate_operations.c $(INC) $(LIB)
	@mv checker ../
clean:
	@make clean -C ../libft
	@echo ".o files removed!"

fclean:
	@make fclean -C ../libft
	@echo ".a file and .o files removed!"

re: fclean all
