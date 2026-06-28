NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDES    = -I. -Ilibft -Iprintf

SRCS        = main.c \
              parsing.c \
              algorithm_simple.c \
              sort_medium.c \
              sort_complex.c \
              op_push.c \
              op_swap.c \
              op_rotate.c \
              op_rev_rotate.c \
              utils_memory.c \
              utils_math.c \
              stack_utils.c

OBJS        = $(SRCS:.c=.o)

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

PRINTF_DIR  = printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re