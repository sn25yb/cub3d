CC = cc
# CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L./libft \
		  -L./mlx \

LDLIBS = -lft \
		 -lmlx \
		 -lm

CPPFLAGS = -I. \
		   -I./libft \
		   -I./mlx \
		   -MMD -MP

MLXFLAG = -framework OpenGL -framework AppKit

SRCDIR1 = ./srcs/sohykim/
SRCDIR3 = ./srcs/sohykim/map2d/
SRCDIR4 = ./srcs/sohykim/validation/
SRCDIR2 = ./srcs/yubshin/
BASE = ./base/

SRCS = main.c \
	   exit.c \
	   event.c \
	   draw.c \
	   $(SRCDIR1)map.c \
	   $(SRCDIR1)setting.c \
	   $(SRCDIR1)rule.c \
	   $(SRCDIR3)inventory.c \
	   $(SRCDIR3)map2d.c \
	   $(SRCDIR4)arg.c \
	   $(SRCDIR4)door.c \
	   $(SRCDIR4)player.c \
	   $(SRCDIR4)object.c \
	   $(SRCDIR4)wall.c \
	   $(SRCDIR3)image2d.c \
	   $(SRCDIR2)add_image3d.c \
	   $(SRCDIR2)get_image3d_addr.c \
	   $(SRCDIR2)rendering.c \

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
NAME = baobao

all : $(NAME)

$(NAME): $(OBJS)
	make -C mlx
	make -C libft
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $(MLXFLAG) -o $@ $^

-include $(DEPS)

$(SRCDIR1)%.o : $(SRCDIR1)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCDIR2)%.o : $(SRCDIR2)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCDIR3)%.o : $(SRCDIR3)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(SRCDIR4)%.o : $(SRCDIR4)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

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
