# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psergean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 17:18:01 by psergean          #+#    #+#              #
#    Updated: 2017/09/14 13:19:21 by psergean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

FLAGS = -Wall -Wextra -Werror

FLAGS_MLX = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

CC = gcc

SRCS = ./srcs/main.c\
	./srcs/init.c\
	./srcs/exit_error.c\
	./srcs/key_hook.c\
	./srcs/mlx_management.c\
	./srcs/pixels_and_colors.c\
	./srcs/cam.c\
	./srcs/raytracer.c\
	./srcs/vpul.c\

OBJS = $(SRCS:.c=.o)

LIBFT = -L./libft -lft

LIBFT_PATH = ./libft

MLX_PATH = ./minilibx_macos

INC = ./includes

all: $(NAME)

$(NAME):$(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I $(INC) $(FLAGS_MLX) $(LIBFT)

clean:
	rm -rf $(OBJS)
	rm -rf ./includes/rtv1.h.gch
	rm -rf ./rtv1.dSYM
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf ./includes/rtv1.h.gch
	rm -rf ./rtv1.dSYM
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
