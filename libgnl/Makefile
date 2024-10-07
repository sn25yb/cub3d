CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iget_next_line.h
SRCS = get_next_line.c

OBJS = $(SRCS:.c=.o)
NAME = libgnl.a

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
