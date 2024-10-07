CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iqueue.h
SRCS = queue.c \
		pair.c

OBJS = $(SRCS:.c=.o)
NAME = libqueue.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $?

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY: all clean fclean re
