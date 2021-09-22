# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojas-e <mrojas-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 14:53:01 by mrojas-e          #+#    #+#              #
#    Updated: 2021/09/20 21:12:50 by mrojas-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = client.c server.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Werror -Wextra
PRINTF_PATH = ./printf/libftprintf.a

all: server client 

server: server.o $(PRINTF_PATH)
	gcc -o server server.o $(PRINTF_PATH)


client: client.o $(OBJECTS) $(PRINTF_PATH)
	gcc -o client client.o $(PRINTF_PATH)

$(PRINTF_PATH): 
	make -C ./printf

clean:
	rm -f $(OBJECTS)
	make -C ./printf clean


fclean: clean
	rm -f server client 
	make -C ./printf fclean
re: fclean all

.PHONY: all clean fclean re