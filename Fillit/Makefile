# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psergean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 14:53:43 by psergean          #+#    #+#              #
#    Updated: 2017/01/16 15:45:17 by psergean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c \
		ft_get_file_data.c \
		ft_exit.c \
		ft_check_fd_ret_chars.c \
		ft_check_tetri_max.c \
		ft_verify_ac.c \
		ft_get_tetri_data.c \
		ft_wood_of_if.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -I.

LIBFT = ./libft

all: $(NAME)

$(NAME):$(OBJS)
	make -C $(LIBFT)
	gcc $(FLAGS) $(SRCS) -L./libft -lft -o $(NAME) -g

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
