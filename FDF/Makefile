# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psergean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 17:18:01 by psergean          #+#    #+#              #
#    Updated: 2017/09/13 16:40:07 by psergean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

FLAGS_MLX = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

CC = gcc

SRCS = ./srcs/main.c\
	./srcs/key_hook.c\
	./srcs/init.c\
	./srcs/parse.c\
	./srcs/draw.c\
	./srcs/view.c\
	./srcs/display.c\
	./srcs/exit_error.c

OBJS = $(SRCS:.c=.o)

LIBFT = -L./libft -lft

LIBFT_PATH = ./libft

MLX_PATH = ./minilibx_macos

INC = ./includes

all: $(NAME)

$(NAME):$(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I$(INC) $(FLAGS_MLX) $(LIBFT)

clean:
	rm -rf $(OBJS)
	rm -rf ./includes/fdf.h.gch
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf ./includes/fdf.h.gch
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
