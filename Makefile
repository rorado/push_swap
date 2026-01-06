SRC     = push_swap.c ft_split.c ft_helpers.c ft_atoi.c
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
