NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = main.c \
       utils.c \
       args.c \
       heap.c \
       dongle.c \
       simulation.c \
       monitor.c \
       init.c \
       utils_2.c \
       simulation_utils.c \
       dongle_utils.c \
       error_message.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c codexion.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
