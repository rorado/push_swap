SRC     = push_swap.c ft_split.c ft_helpers.c ft_atoi.c parsing.c utils.c \
          stack.c operations_swap.c operations_push.c operations_rotate.c \
          operations_rev_rotate.c sort_small.c sort_big.c sort.c
OBJS    = $(SRC:.c=.o)

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
