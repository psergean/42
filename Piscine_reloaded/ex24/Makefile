# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psergean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 11:14:00 by psergean          #+#    #+#              #
#    Updated: 2016/11/11 11:36:12 by psergean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c\
		 ./srcs/ft_putstr.c\
		  ./srcs/ft_swap.c\
		  ./srcs/ft_strlen.c\
		  ./srcs/ft_strcmp.c

FLAGS = -Wall -Werror -Wextra

HEADERS = ./includes

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I $(HEADERS)
	ar rc $(NAME) ft_putchar.o\
	   	ft_putstr.o\
	   	ft_swap.o\
	   	ft_strlen.o\
	   	ft_strcmp.o
	ranlib $(NAME)

clean:
	/bin/rm -f ft_putchar.o ft_putstr.o ft_swap.o\
	   	ft_strlen.o ft_strcmp.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
