CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L./libft \
		  -L./mlx \
		  -L./libgnl \
		  -L./queue \

LDLIBS = -lft \
		 -lmlx \
		 -lgnl \
		 -lqueue \
		 -lm

CPPFLAGS = -I. \
		   -I./libft \
		   -I./mlx \
		   -I./libgnl \
		   -I./queue \
		   -MMD -MP

MLXFLAG = -framework OpenGL -framework AppKit

SRCDIR1 = ./srcs/sohykim/

SRCS = main.c \
	   exit.c \
	   $(SRCDIR1)map.c \
	   $(SRCDIR1)setting.c \
	   $(SRCDIR1)valid.c \
	   $(SRCDIR1)lib.c \
	   $(SRCDIR1)img.c \

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
NAME = baobao

all : $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	make -C libft
	make -C queue
	make -C libgnl
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(MLXFLAG) -o $@ $^

-include $(DEPS)

$(SRCDIR1)%.o : $(SRCDIR1)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<


%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean :
	make clean -C mlx
	make clean -C libft
	make clean -C queue
	make clean -C libgnl
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean : clean
	rm -f libft/libft.a
	rm -f mlx/libmlx.a
	rm -f queue/libqueue.a
	rm -f libgnl/libgnl.a
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re
