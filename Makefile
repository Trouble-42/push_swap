CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

SRCS = ft_atoi.c			\
	   ft_count.c			\
	   ft_disorder.c		\
	   ft_is_sorted.c		\
	   ft_pilelen.c			\
	   ft_push.c			\
	   ft_radix.c			\
	   ft_rank.c			\
	   ft_reverse_rotate.c	\
	   ft_rotate.c			\
	   ft_select.c			\
	   ft_swap.c			\
	   main.c

OBJS = $(SRCS:.c=.o)

PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	make -C ft_printf

%.o: %.c ft_push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
