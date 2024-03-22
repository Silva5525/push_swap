# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 17:31:12 by wdegraf           #+#    #+#              #
#    Updated: 2024/02/13 17:31:13 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:= so_long
CC	:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42
LIBFT	:= ./libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit -L$(LIBFT) -lft

SRCS	:= main.c 
OBJS	:= ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean 

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft

