# Program name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Header directory
INCLUDES = -Iinclude

# Source root directory
SRC_DIR = src

# Source files
SRCS = \
	$(SRC_DIR)/main/main.c \
	$(SRC_DIR)/main/main_utils.c \
	\
	$(SRC_DIR)/parsing/ft_parsing.c \
	$(SRC_DIR)/parsing/ft_atoi.c \
	$(SRC_DIR)/parsing/ft_flags.c \
	\
	$(SRC_DIR)/stack/ft_pile_utils.c \
	$(SRC_DIR)/stack/ft_pilelen.c \
	$(SRC_DIR)/stack/ft_count.c \
	$(SRC_DIR)/stack/ft_sum_total.c \
	\
	$(SRC_DIR)/operations/ft_push.c \
	$(SRC_DIR)/operations/ft_swap.c \
	$(SRC_DIR)/operations/ft_rotate.c \
	$(SRC_DIR)/operations/ft_reverse_rotate.c \
	\
	$(SRC_DIR)/sorting/ft_sort.c \
	$(SRC_DIR)/sorting/ft_select.c \
	$(SRC_DIR)/sorting/ft_radix.c \
	$(SRC_DIR)/sorting/ft_chunk.c \
	$(SRC_DIR)/sorting/ft_chunk_utils.c \
	$(SRC_DIR)/sorting/ft_adaptive.c \
	\
	$(SRC_DIR)/ranking/ft_rank.c \
	\
	$(SRC_DIR)/turk/ft_turk.c \
	$(SRC_DIR)/turk/ft_turk_cost.c \
	$(SRC_DIR)/turk/ft_turk_move.c \
	$(SRC_DIR)/turk/ft_turk_utils.c \
	\
	$(SRC_DIR)/stats/ft_bench.c \
	$(SRC_DIR)/stats/ft_disorder.c \
	$(SRC_DIR)/stats/ft_print_strat.c \
	\
	$(SRC_DIR)/checks/ft_is_sorted.c

# Object files
OBJS = $(SRCS:.c=.o)

# ft_printf library
PRINTF = ft_printf/libftprintf.a

# Default rule
all: $(NAME)

# Build executable
$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

# Build ft_printf
$(PRINTF):
	$(MAKE) -C ft_printf

# Compile source files
%.o: %.c include/ft_push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)
	$(MAKE) -C ft_printf clean

# Remove object files and executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean

# Full rebuild
re: fclean all

# Phony targets
.PHONY: all clean fclean re