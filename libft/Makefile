# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 11:38:11 by mrojas-e          #+#    #+#              #
#    Updated: 2021/07/10 16:27:34 by mrojas-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c

all: $(NAME)


$(NAME):
	cc  -Wall -Werror -Wextra -c $(SRC)
	ar -crs $(NAME) *.o 

clean: 
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
