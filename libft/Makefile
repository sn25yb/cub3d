CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I./libft \
			-I./queue \
			-I./libgnl \
			-I./base

BASE = ./base
LIBFT = ./libft
GNL = ./libgnl
QUEUE = ./queue

SRCS1 = $(LIBFT)/ft_isalpha.c \
	  $(LIBFT)/ft_isdigit.c \
	  $(LIBFT)/ft_isalnum.c \
	  $(LIBFT)/ft_isascii.c \
	  $(LIBFT)/ft_isprint.c \
	  $(LIBFT)/ft_strlen.c \
	  $(LIBFT)/ft_memset.c \
	  $(LIBFT)/ft_bzero.c \
	  $(LIBFT)/ft_memcpy.c \
	  $(LIBFT)/ft_memmove.c \
	  $(LIBFT)/ft_strlcpy.c \
	  $(LIBFT)/ft_strlcat.c \
	  $(LIBFT)/ft_toupper.c \
	  $(LIBFT)/ft_tolower.c \
	  $(LIBFT)/ft_strchr.c \
	  $(LIBFT)/ft_strrchr.c \
	  $(LIBFT)/ft_strncmp.c \
	  $(LIBFT)/ft_memchr.c \
	  $(LIBFT)/ft_memcmp.c \
	  $(LIBFT)/ft_strnstr.c \
	  $(LIBFT)/ft_atoi.c \
	  $(LIBFT)/ft_calloc.c \
	  $(LIBFT)/ft_strdup.c \
	  $(LIBFT)/ft_substr.c \
	  $(LIBFT)/ft_strjoin.c \
	  $(LIBFT)/ft_strtrim.c \
	  $(LIBFT)/ft_split.c \
	  $(LIBFT)/ft_itoa.c \
	  $(LIBFT)/ft_strmapi.c \
	  $(LIBFT)/ft_striteri.c  \
	  $(LIBFT)/ft_putchar_fd.c \
	  $(LIBFT)/ft_putstr_fd.c \
	  $(LIBFT)/ft_putendl_fd.c \
	  $(LIBFT)/ft_putnbr_fd.c \

SRCS2 = $(BASE)/lib.c \
	  $(BASE)/pair.c

SRCS3 = $(GNL)/get_next_line.c
SRCS4 = $(QUEUE)/queue.c \
		$(QUEUE)/lifecycle.c

OBJS1 = $(patsubst $(LIBFT)/%.c, $(LIBFT)/%.o, $(SRCS1))
OBJS2 = $(patsubst $(BASE)/%.c, $(BASE)/%.o, $(SRCS2))
OBJS3 = $(patsubst $(GNL)/%.c, $(GNL)/%.o, $(SRCS3))
OBJS4 = $(patsubst $(QUEUE)/%.c, $(QUEUE)/%.o, $(SRCS4))

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS1) $(OBJS2) $(OBJS3) $(OBJS4)
	ar -rcs $@ $^

$(LIBFT)%.o: $(LIBFT)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $?

$(BASE)%.o: $(BASE)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $?

$(GNL)%.o: $(GNL)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $?

$(QUEUE)%.o: $(QUEUE)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $?


clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	rm -f $(OBJS3)
	rm -f $(OBJS4)

fclean: clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY: all clean fclean re
