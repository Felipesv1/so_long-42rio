

NAME = so_long
LIBMLX = ../minilibx/libmlx_Linux.a
SRC = main.c map_start.c  init.c read_map.c exit_game.c start_moves.c moves.c check_map.c gameplay.c
FLAGSMLX = -Lmlx -lXext -lX11
CFLAGS = -Wall -Werror -Wextra
CC  = cc
RM = rm -rf

LIBFT = libft.a



OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBMLX) $(FLAGSMLX) libft/$(LIBFT) -o $(NAME)
	@echo Compilation Finish

clean: 
	@make clean -C libft
	${RM} ${OBJ}

fclean: clean
	@make fclean -C libft
	${RM} $(NAME)
	${RM} $(LIBFT)

re: fclean all
