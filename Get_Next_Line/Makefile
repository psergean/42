NAME = YOLO

SRCS = main.c \
		get_next_line.c

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
