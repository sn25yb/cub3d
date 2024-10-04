CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L./libft \
		  -L./mlx \

LDLIBS = -lft \
		 -lmlx \

CPPFLAGS = -I. \
		   -I./libft \
		   -I./mlx \
		   -MMD -MP

SRCS = main.c \
	   srcs/map.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
NAME = baobao

all : $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	make -C libft
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $@ $^

-include $(DEPS)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $<

clean :
	make clean -C mlx
	make clean -C libft
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean : clean
	rm -f libft/libft.a
	rm -f mlx/libmlx.a
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re
