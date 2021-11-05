# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 23:32:22 by mrojas-e          #+#    #+#              #
#    Updated: 2021/11/02 22:55:05 by mrojas-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#====Variables====#

NAME = Push_Swap
SRCS_PATH = src/
HEADERS_FOLDER = -I includes/
SRCS =	./src/push_swap.c ./utils/list_utils.c\
		./src/error_handling.c ./utils/sorting.c\
		./operations/push_pop.c ./operations/reverse_rotate.c\
		./operations/rotate.c ./operations/swap.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar crs
LIBFT_LIB = libft.a
LIBFT_PATH = libft/
LIBFT_OBJS = ${LIBFT_PATH}*.o
LIBFTMAKE = $(MAKE) -C ${LIBFT_PATH}

#====COLORS====#

LILA := \033[0;35m
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m

#====RULES====#

all:	${NAME}

pmake:
	@${LIBFTMAKE}
	@echo "$(LILA)           $(NAME) is Ready!$(NC)"
	@echo "$(LILA)          ---------------------$(NC)"
	@echo "$(LILA)             Libft is Ready!$(NC)$(NC)"
	@echo "$(LILA)            -----------------$(NC)"

${NAME}: pmake
	@${CC} ${CFLAGS} ${HEADERS_FOLDER} ${SRCS} ${LIBFT_PATH}${LIBFT_LIB} -o ${NAME}

clean:
	@make -C ${LIBFT_PATH} clean
	@echo "$(RED)    __________________________________$(NC)"
	@echo "$(RED)      $(NAME) object-files DELETED!$(NC)"
	
fclean: 	clean
	@${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}
	@echo "$(RED)            FULL CLEAN COMPLETED!$(NC)"
	@echo "$(RED)      ------------------------------$(NC)"

re: fclean all

.PHONY: @all clean fclean re