# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tapperce <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 09:37:33 by tapperce          #+#    #+#              #
#    Updated: 2018/02/27 13:27:01 by tapperce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvec.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
ARRCS = ar rcs
RANLIB = ranlib

INC_PATH = ./includes/
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
	
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = libvec.h
SRC_NAME = vec_normalise3.c vec_add3.c vec_sub3.c vec_mult3.c vec_dot3.c \
		   vec_cross3.c vec_length3.c vec_normalise2.c vec_add2.c vec_sub2.c \
		   vec_mult2.c vec_dot2.c vec_length2.c mat_create44.c mat_product44.c \
		   mat_transpose44.c mat_multpmat44.c mat_multvmat44.c mat_inverse4x4.c \
		   mat_rotate.c mat_translate.c mat_free44.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
INC = $(addprefix -I,$(INC_PATH))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(ARRCS) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) -c $(CFLAGS) $(INC) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
