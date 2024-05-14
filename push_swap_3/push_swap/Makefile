# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 11:57:39 by wdegraf           #+#    #+#              #
#    Updated: 2024/03/28 13:31:29 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -Wunreachable-code -Ofast -g -fsanitize=address
LIBFT	:= ./libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

# MacOS
# LIBS	:= -L$(LIBFT) -lft
# linux
LIBS := -L$(LIBFT) -lft


SRCS	:= main.c exit_manager.c first_utils.c push_swap.c push.c rotation.c \
			reverse_rotation.c sort.c swap.c
OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

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
