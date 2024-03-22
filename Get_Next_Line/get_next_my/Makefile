# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 10:35:50 by wdegraf           #+#    #+#              #
#    Updated: 2023/12/21 21:04:25 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =  -Wall -Wextra -Werror -g
BUFFER = -D BUFFER_SIZE=214
NAME = libgetnextline.a
NAME_BONUS = libgetnextline_bonus.a

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS_BONUS)
	ar rcs $(NAME_BONUS) $(OBJS_BONUS)

%.o: %.c 
	$(CC) $(CFLAGS) $(BUFFER) $(INCLUDES) -c $< -o $@ 
	
bonus: $(OBJS_BONUS)
	ar rcs $(NAME_BONUS) $(OBJS_BONUS)

test: $(NAME)
	$(CC) $(CFLAGS) $(BUFFER) $(NAME) main.c -o test -L. -lgetnextline -I.

test_bonus: $(NAME_BONUS)
	$(CC) $(CFLAGS) $(BUFFER) $(NAME_BONUS) main.c -o test_bonus -L. -lgetnextline_bonus -I.

%.o: %.c 
	$(CC) $(CFLAGS) $(BUFFER) $(INCLUDES) -c $< -o $@ 

clean: 
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean 
	rm -rf $(NAME) $(NAME_BONUS) test test_bonus

fclean_bonus: clean 
	rm -rf $(NAME_BONUS) test_bonus

re: fclean all 

.PHONY: all clean fclean re
