
CC = cc

NAME	:= so_long
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include

# | `Windows NT`     | -lglfw3 -lopengl32 -lgdi32                                    |
# | `MacOS`          | -lglfw(3) -framework Cocoa -framework OpenGL -framework IOKit |
# | `Linux`          | -ldl -lglfw(3) -pthread -lm -DDEBUG=1 -DGLFW_FETCH=0
# **NOTE: For some UNIX systems the flag for glfw might be with or without a 3 at the end.**

# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -DEBUG=1
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit

SRCS	:= main.c animate.c image_utils.c
# SRCS	:= main.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx

# BIN 	= bin
# SRC	= test_main.c animate.c image_utils.c # You will need to add all your src files here if you want you can also use a wildcard
# INCS	= include
# LIBFT_INCS	= $(LIBFT)/includes
# LIBMLX_INCS	= /usr/local/include
# LIBFT	= libft
# LIBMLX  = ./MLX42
# CFLAGS	= -Wall -Werror -Wextra -g -O3 
# LFLAGS	= -L$(LIBFT) -lft -L$(LIBMLX) -lmlx
# IFLAGS	= -I$(INCS) -I$(LIBFT_INCS) -I$(LIBMLX_INCS) 
# UNAME	:= $(shell uname)
# NAME	= animations
# RM	= rm -rf
# OBJS	= $(SRC:src/%c=$(BIN)/%o)

# ifeq ($(UNAME), Darwin)
# 	CC = gcc
# 	LFLAGS += -framework OpenGL -framework AppKit
# else ifeq ($(UNAME), FreeBSD)
# 	CC = clang
# 	LFLAGS += -lbsd -lXext -lX11 -lm
# else
# 	CC	= gcc
# 	CFLAGS += -D LINUX
# 	LFLAGS += -lbsd -lXext -lX11 -lm
# endif

# all: $(NAME)

# $(NAME): ${BIN} ${OBJS} | ${LIBFT}
# 	${CC} ${OBJS} ${LFLAGS} -o ${NAME} 

# $(BIN)/%o: src/%c
# 	${CC} -c $< ${CFLAGS} ${IFLAGS} -o $@

# $(BIN):
# 	mkdir -p $(BIN)

# $(LIBFT):
# 	@make all -C $(LIBFT) --no-print-directory

# clean:
# 	$(RM) $(BIN)

# fclean: clean
# 	$(RM) $(NAME)
# 	@make fclean -C $(LIBFT) --no-print-directory

# re: fclean all

# test:
# 	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME)

# show:
# 	@printf "UNAME		: $(UNAME)\n"
# 	@printf "NAME  		: $(NAME)\n"
# 	@printf "CC		: $(CC)\n"
# 	@printf "CFLAGS		: $(CFLAGS)\n"
# 	@printf "LFLAGS		: $(LFLAGS)\n"
# 	@printf "IFLAGS		: $(IFLAGS)\n"
# 	@printf "SRC		: $(SRC)\n"
# 	@printf "OBJS		: $(OBJS)\n"


# .PHONY: $(LIBFT) re all clean fclean
