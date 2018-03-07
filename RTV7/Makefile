# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tapperce <tapperce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 17:26:42 by tapperce          #+#    #+#              #
#    Updated: 2018/03/07 13:35:08 by tzaaboul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = rtv1

NOC = \033[0m
OKC = \033[32m
WAC = \033[33m

CC = gcc
CC_FLAGS =

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./objs/
LFT_PATH = ./libft/
LVEC_PATH = ./libvec/

SRC_NAME = main.c build_prim.c rt.c intersect.c check_conf.c check_value.c \
		   free_env.c ft_hook.c get_val.c init_objs.c init_val.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = rtv1.h

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LFT_PATH)
		@make -C $(LVEC_PATH)
		@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft -lm -L $(LVEC_PATH) -lvec -lmlx -framework OpenGL -framework AppKit
		@echo "$(OKC)RTv1: Compilation ready$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CC_FLAGS) -g $(INC) -o $@ -c $<

clean:
		@make -C $(LFT_PATH) clean
		@make -C $(LVEC_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "$(WAC)RTv1: objs directory deleted$(NOC)"

fclean: clean
		@make -C $(LFT_PATH) fclean
		@make -C $(LVEC_PATH) fclean
		@rm -rf $(NAME)
		@echo "$(WAC)RTv1: rtv1 file deleted$(NOC)"

re: fclean all
