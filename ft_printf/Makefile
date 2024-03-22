# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 10:35:50 by wdegraf           #+#    #+#              #
#    Updated: 2024/02/01 16:26:41 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = libprintf.a

SRCS = ft_printf.c ft_printf_xXpudi.c
OBJS = $(SRCS:.c=.o)

LIBFT_SRC = ./libft

LIBFT_OBJS = $(LIBFT_SRC:.c=.o)

INCLUDES = -I $(LIBFT_SRC)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_SRC) bonus
	cp ./libft/libft.a ./libftprintf.a
	ar rcs $(NAME) $(OBJS) 

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

test: $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(NAME) main.c -o test

clean: 
	rm -rf $(OBJS) 
	$(MAKE) -C $(LIBFT_SRC) clean

fclean: clean 
	rm -rf $(NAME) test
	$(MAKE) -C $(LIBFT_SRC) fclean

re: fclean all 

.PHONY: all clean fclean re 