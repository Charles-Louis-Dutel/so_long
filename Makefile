NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror

###########################Sources#############################
SRCS_DIR = sources/
FILES = \
	so_long.c parse_map.c utils.c check_path.c \
	game.c display_map.c moves.c\

SRCS = $(addprefix $(SRCS_DIR), $(FILES))

BONUS_DIR = bonus/
FILES_BONUS = \
	so_long_bonus.c parse_map_bonus.c utils_bonus.c \
	check_path_bonus.c game_bonus.c display_map_bonus.c \
	moves_bonus.c ennemy_move_bonus.c \
	
SRCS_BONUS = $(addprefix $(BONUS_DIR), $(FILES_BONUS))

###########################Objects#############################
#OBJ_DIR = obj/
#OBJS = $(addprefix $(OBJ_DIR), ${SRCS:.c=.o})
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
OBJS_ALL = ${OBJS} ${OBJS_BONUS}

###########################Libs#############################
LIBFT = includes/libft.a
FT_PRINTF = includes/libftprintf.a
GNL = includes/libgnl.a
LIBX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
ALL_LIB = ${LIBFT} ${FT_PRINTF} ${GNL}

###########################Rules#############################

all: ${NAME} bonus

${NAME}: ${OBJS}
	@make -C ./minilibx-linux
	${CC} ${CFLAGS} ${OBJS} ${ALL_LIB} ${LIBX} -o ${NAME}

bonus: ${OBJS_BONUS}
	@make -C ./minilibx-linux
	${CC} ${CFLAGS} ${OBJS_BONUS} ${ALL_LIB} ${LIBX} -o ${NAME_BONUS}

clean:
	@make clean -C ./minilibx-linux
	rm -f ${OBJS_ALL}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
