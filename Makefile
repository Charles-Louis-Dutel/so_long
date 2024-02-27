NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

###########################Sources#############################
SRCS_DIR = sources/
FILES = \
	so_long.c parse_map.c utils.c check_path.c \
	game.c display_map.c moves.c endgame.c \
	set_images.c \

SRCS = $(addprefix $(SRCS_DIR), $(FILES))

BONUS_DIR = bonus/
FILES_BONUS = \
	so_long_bonus.c parse_map_bonus.c utils_bonus.c \
	check_path_bonus.c game_bonus.c display_map_bonus.c \
	moves_bonus.c ennemy_move_bonus.c print_new_map.c \
	set_images_bonus.c endgame_bonus.c\

SRCS_BONUS = $(addprefix $(BONUS_DIR), $(FILES_BONUS))

###########################Objects#############################
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
OBJS_ALL = ${OBJS} ${OBJS_BONUS}

###########################Libs#############################
LIBFT = libft/libft.a
FT_PRINTF = libft/ft_printf/libftprintf.a
GNL = libft/get_next_line/libgnl.a
LIBX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
ALL_LIB = ${LIBFT} ${FT_PRINTF} ${GNL}

###########################Rules#############################

${NAME}: ${OBJS}
	@make -C ./minilibx-linux
	@${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ${ALL_LIB} ${LIBX} -o ${NAME}

all: ${NAME} bonus

bonus: ${OBJS_BONUS}
	@make -C ./minilibx-linux
	@${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS_BONUS} ${ALL_LIB} ${LIBX} -o ${NAME_BONUS}

clean:
	@make clean -C ./minilibx-linux
	@${MAKE} -C ./libft fclean
	rm -f ${OBJS_ALL}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
