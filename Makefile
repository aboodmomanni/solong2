NAME = so_long.a
CFLAGS = -Wall -Wextra -Werror
MLXDIR = ./mlx
SRCS = main.c MapMaker.c MainUtils.c Checkers.c Keys.c actions.c utils.c ValidateMap.c AllFrees.c

MLX = ./mlx/libmlx.a

LIBFT_DIR = ./libft
LIBFT_NAME = ./libft/libft.a

OBJ = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
		make -C ${LIBFT_DIR}
		make -C ${MLXDIR}
		ar rcs ${NAME} ${OBJ}
		cc ${CFLAGS} -o so_long ${SRCS} ${LIBFT_NAME} ${MLX} ${NAME} -lX11 -lXext -lm
		
clean:
		make clean -C ${LIBFT_DIR}
		make clean -C ${MLXDIR}
		rm -f ${OBJ}

fclean: clean
		make fclean -C ${LIBFT_DIR}
		rm -f ${NAME} so_long

re: fclean all

.PHONY: all clean fclean re