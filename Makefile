NAME = so_long
#NAME_BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror

###########################Sources#############################
SRCS = \
	so_long.c parse_map.c utils.c check_path.c \

#SRCS_BONUS =

###########################Objects#############################
OBJS = ${SRCS:.c=.o}
#OBJS_BONUS = ${SRCS_BONUS:.c=.o}
#OBJS_ALL = ${OBJS} ${OBJS_BONUS}

###########################Libs#############################
LIBFT = includes/libft.a
FT_PRINTF = includes/libftprintf.a
GNL = includes/libgnl.a
LIBX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
ALL_LIB = ${LIBFT} ${FT_PRINTF} ${GNL}

###########################Rules#############################
all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${ALL_LIB} ${LIBX} -o ${NAME}

#bonus: ${OBJS_BONUS}
#	${CC} ${CFLAGS} ${OBJS_BONUS} ${ALL_LIB} -o ${NAME_BONUS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
#	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
