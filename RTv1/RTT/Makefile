# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzaaboul <tzaaboul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 17:26:42 by tzaaboul          #+#    #+#              #
#    Updated: 2018/02/01 18:43:25 by tapperce         ###   ########.fr        #
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

SRC_NAME = main.c free_env.c init_val.c check_conf.c check_value.c check_objs.c\
		   get_val.c ft_atod.c init_objs.c coord_inter.c get_dir.c get_vp.c hit.c\
		   hit_sphere.c lhit.c rt.c hit_plan.c hit_cylinder.c vectordot.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = rtv1.h

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LFT_PATH)
		@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft -lmlx -framework OpenGL -framework AppKit
		@echo "$(OKC)RTv1: Compilation ready$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
		@make -C $(LFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "$(WAC)RTv1: objs directory deleted$(NOC)"

fclean: clean
		@make -C $(LFT_PATH) fclean
		@rm -rf $(NAME)
		@echo "$(WAC)RTv1: rtv1 file deleted$(NOC)"

re: fclean all
