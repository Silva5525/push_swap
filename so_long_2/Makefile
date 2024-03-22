# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 13:40:15 by wdegraf           #+#    #+#              #
#    Updated: 2024/03/15 17:21:55 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -Wunreachable-code -Ofast -g
LIBMLX	:= ./MLX42
LIBFT	:= ./libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit -L$(LIBFT) -lft

SRCS	:= so_long.c big_util.c rendering.c fail_manager.c wall_?.c
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
#-ldl -lglfw -lm  -L$(LIBFT) -lft $(LIBMLX)/build/libmlx42.a

clean:
	@rm -rf $(OBJS)
# @rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

t: $(NAME)
	./$(NAME) 

ret: re t

.PHONY: all, clean, fclean, re, libmlx, libft