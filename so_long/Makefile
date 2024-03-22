# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 12:47:00 by wdegraf           #+#    #+#              #
#    Updated: 2024/03/06 13:44:18 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC = cc

# NAME	:= so_long
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
# LIBMLX	:= ./MLX42

# HEADERS	:= -I ./include -I $(LIBMLX)/include

# # | `Windows NT`     | -lglfw3 -lopengl32 -lgdi32                                    |
# # | `MacOS`          | -lglfw(3) -framework Cocoa -framework OpenGL -framework IOKit |
# # | `Linux`          | -ldl -lglfw(3) -pthread -lm -DDEBUG=1 -DGLFW_FETCH=0
# # **NOTE: For some UNIX systems the flag for glfw might be with or without a 3 at the end.**

# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -DEBUG=1

# SRCS	:= so_long.c big_util.c small_util.c rendering.c 

# all: libmlx $(NAME)

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# $(NAME): $(OBJS)
# 	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

# clean:
# 	@rm -rf $(OBJS)
# 	@rm -rf $(LIBMLX)/build

# fclean: clean
# 	@rm -rf $(NAME)

# re: clean all

# .PHONY: all, clean, fclean, re, libmlx

NAME	:= so_long
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
LIBMLX	:= ./MLX42
LIBFT	:= ./libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit -L$(LIBFT) -lft

SRCS	:= so_long.c big_util.c small_util.c rendering.c
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