CC = gcc
CFLAGS = -Wextra -Werror -Wall

NAME = push_swap

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC = 	ft_utils.c 	\
		ops.c		\
		main.c 		\
		ft_split_utils.c \
		ft_sort.c \
		ft_stack_utils.c \
		ft_more_utils.c \
		ft_swap.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		ft_push.c \
		ft_sort_utils.c \
		ft_parsing_utils.c \
		ft_free_utils.c \
		ft_array_utils.c \
		ft_count_and_finder.c \
		ft_lot_utils.c \
		ft_sort_three.c \

SRCS = $(addprefix $(DIR_S),$(SRC))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(DIR_H) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) -I $(DIR_H) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
