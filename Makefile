NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
INCLUDES    = -I includes/ -Ilibft -Iprintf

SRCS        = srcs/main.c \
              srcs/parsing.c \
              srcs/algorithm_simple.c \
              srcs/sort_medium.c \
              srcs/sort_complex.c \
              srcs/op_push.c \
              srcs/op_swap.c \
              srcs/op_rotate.c \
              srcs/op_rev_rotate.c \
              srcs/utils_memory.c \
              srcs/utils_math.c \
              srcs/stack_utils.c

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
