CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

SRCS = ft_address.c			\
	   ft_printf.c 			\
	   ft_putchar.c 		\
	   ft_putnbr_c.c 		\
	   ft_putnbrhexacaps.c 	\
	   ft_putnbrhexamin.c 	\
	   ft_putstr_c.c 		\
	   ft_putunsignednbr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
