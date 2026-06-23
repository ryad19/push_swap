NAME = libftprintf.a

HDR = ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

ARC = ar rcs

SRCS = ft_putchar.c ft_putnbr.c ft_putstr.c ft_putptr.c ft_printf.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(ARC) $(NAME) $(OBJ)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
