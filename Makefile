CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
BONUS = checker

HEADER = mandatory/push_swap.h
BONUS_HEADER = bonus/bonus_push_swap.h

SRC = \
	mandatory/main.c \
	mandatory/input_check.c mandatory/input_check_utils.c \
	mandatory/initialization.c \
	mandatory/stack.c \
	mandatory/swap.c mandatory/push.c mandatory/rotate.c mandatory/reverse_rotate.c \
	mandatory/sort_tiny.c mandatory/sort.c \
	mandatory/position.c mandatory/cost.c mandatory/do_move.c \
	mandatory/utils.c mandatory/ft_split.c

BONUS_SRCS = \
	bonus/bonus_main.c \
	bonus/bonus_input_check.c \
	bonus/bonus_utils.c \
	bonus/bonus_helps_functions.c \
	bonus/bonus_ft_split.c \
	bonus/bonus_get_next_line.c \
	bonus/bonus_get_next_line_utils.c \
	bonus/bonus_stack.c \
	bonus/bonus_push.c \
	bonus/bonus_swap.c \
	bonus/bonus_rotate.c \
	bonus/bonus_reverse_rotate.c \
	bonus/bonus_utils_extra.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

mandatory/%.o: mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(BONUS_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
