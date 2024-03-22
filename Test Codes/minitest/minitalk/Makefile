# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 12:47:00 by wdegraf           #+#    #+#              #
#    Updated: 2024/01/22 16:54:03 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c

LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) $(LIBFT_A)

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) $(LIBFT_A)

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_SRCS) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_SRCS) $(LIBFT_A)

$(SERVER_BONUS_NAME): $(SERVER_BONUS_SRCS) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_SRCS) $(LIBFT_A)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

.PHONY: all clean fclean re bonus