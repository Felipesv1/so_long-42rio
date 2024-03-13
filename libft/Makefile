NAME = libft.a

CC = cc

CFLAGS =  -Wall -Werror -Wextra 

FILESC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c ft_strtrim.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c ft_split.c \
ft_printf.c check_type_input.c print_int.c print_string.c print_unsnbr.c print_hex.c print_char.c  get_next_line.c  get_next_line_utils.c \

OBJS = $(FILESC:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f  $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all fclean clean re

