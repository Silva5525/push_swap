# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 11:57:39 by wdegraf           #+#    #+#              #
#    Updated: 2024/03/22 11:58:28 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -Wunreachable-code -Ofast -g -fsanitize=address
LIBMLX	:= ./MLX42
LIBFT	:= ./libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

# MacOS
# LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit -L$(LIBFT) -lft
# linux
LIBS := $(LIBMLX)/build/libmlx42.a $(shell pkg-config --static --libs glfw3 gl) -L$(LIBFT) -lft
# LIBS	:= -L$(LIBFT) -lft $(LIBMLX)/build/libmlx42.a $(shell pkg-config --static --libs glfw3) -ldl


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
	@$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(HEADERS) -o $(NAME) 
#-ldl -lglfw -lm  -L$(LIBFT) -lft $(LIBMLX)/build/libmlx42.a

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

# $(NAME): $(OBJS)
# 	$(CC) -v $(OBJS) $(CFLAGS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

t: $(NAME)
	./$(NAME) 

ret: re t

.PHONY: all, clean, fclean, re, libmlx, libft
