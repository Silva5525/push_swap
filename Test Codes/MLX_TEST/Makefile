CC = cc

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./include/mlx
LIBFT	:= libft

HEADERS	:= -I ./include -I $(LIBMLX)/include

# | `Windows NT`     | -lglfw3 -lopengl32 -lgdi32                                    |
# | `MacOS`          | -lglfw(3) -framework Cocoa -framework OpenGL -framework IOKit |
# | `Linux`          | -ldl -lglfw(3) -pthread -lm -DDEBUG=1 -DGLFW_FETCH=0
# **NOTE: For some UNIX systems the flag for glfw might be with or without a 3 at the end.**

LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/build/libft.a -ldl -lglfw -pthread -lm -DEBUG=1

SRCS	:= src/image_utils.c src/main.c src/window_utils.c  
# SRCS	:= main.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)
	@cmake $(LIBFT) -B $(LIBFT)/build && make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBFT)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx