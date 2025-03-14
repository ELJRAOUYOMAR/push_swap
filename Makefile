# Program name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = libft
INCLUDES = -I. -I$(LIBFT_DIR)

# Source files
SRCS = push_swap.c                        \
       operations/push.c                  \
       operations/swap.c                  \
       operations/rotate.c                \
       operations/reverse_rotate.c        \
       utils/stack_utils1.c               \
       utils/stack_utils2.c               \
       utils/string_utils.c               \
       parser.c                           \
       chunks.c                           \
       print_array.c

# Object files
OBJS = $(SRCS:.c=.o)

# Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Rules
all: $(LIBFT) $(NAME)

# Compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile push_swap
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re