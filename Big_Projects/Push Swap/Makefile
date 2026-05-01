NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = atoi.c \
              input_utils___one.c \
              input_utils___two.c \
              input.c \
              push_swap.c \
              sorting_utils__five.c \
              sorting_utils__for.c \
              sorting_utils__one.c \
              sorting_utils__thre.c \
              sorting_utils__two.c \
              sorting.c \
              split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re