NAME = so_long.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MINIDIR = ./mlx
SRCS = srcs/main.c srcs/MapMaker.c srcs/MainUtils.c srcs/Checkers.c srcs/Keys.c srcs/actions.c srcs/utils.c srcs/ValidateMap.c srcs/AllFrees.c srcs/ValidateMap2.c

MLX = ./mlx/libmlx.a

LIBFT_DIR = ./libft
LIBFT_NAME = ./libft/libft.a

OBJ = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
		make -C ${LIBFT_DIR}
		make -C ${MINIDIR}
		ar rcs ${NAME} ${OBJ}
		${CC} ${CFLAGS} -o so_long ${SRCS} ${LIBFT_NAME} ${MLX} ${NAME} -lX11 -lXext -lm
		
clean:
		make clean -C ${LIBFT_DIR}
		make clean -C ${MINIDIR}
		${RM} ${OBJ}

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} ${NAME} so_long

re: fclean all

.PHONY: all clean fclean re