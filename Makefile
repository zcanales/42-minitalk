# **************************************************************************** #
#                                                                              #
#                                                           :::      ::::::::  #
#  Makefile                                               :+:      :+:    :+:  #
#                                                       +:+ +:+         +:+    #
#  By: zcanales <zcanales@student.42urduliz.com>      +#+  +:+       +#+       #
#                                                   +#+#+#+#+#+   +#+          #
#  Created: 2021/07/22 12:11:18 by zcanales              #+#    #+#            #
#  Updated: 2021/08/02 11:21:53 by zcanales             ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_BONUS = bonus/server_bonus
CLIENT_BONUS = bonus/client_bonus

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SERVER_BONUS = bonus/server_bonus.c
SRC_CLIENT_BONUS = bonus/client_bonus.c

LIB_A = Libft/libft.a\

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all : $(SERVER) $(CLIENT)

$(SERVER) : $(LIB_A) $(SRC_SERVER)
	$(CC) $(CFLAG) $(SRC_SERVER) $(LIB_A) -o $(SERVER)

$(CLIENT) : $(LIB_A) $(SRC_CLIENT)
	$(CC) $(CFLAG) $(SRC_CLIENT) $(LIB_A) -o $(CLIENT)

$(LIB_A): Libft/*.c Libft/*.h
	$(MAKE) -C Libft/

bonus:	$(LIB_A) $(SRC_SERVER_BONUS) $(SRC_CLIENT_BONUS)
	$(CC) $(CFLAG) $(SRC_SERVER_BONUS) $(LIB_A) -o $(SERVER_BONUS)
	$(CC) $(CFLAG) $(SRC_CLIENT_BONUS) $(LIB_A) -o $(CLIENT_BONUS)

clean:
	make -C Libft/ clean

fclean: clean
	@echo "Eliminar .o y .a"
	make -C Libft/ fclean
	rm -f $(SERVER) $(CLIENT)
	rm -f $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all 

.PHONY : all clean fclean re bonus
