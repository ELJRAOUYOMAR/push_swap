NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
       operations.c \
       stack_utils.c \
       parser.c \
       chunks.c \
       print_array.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re