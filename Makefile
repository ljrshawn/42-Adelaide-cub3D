CC = cc
ROOT_DIR = $(shell pwd)
LIBFT_DIR = $(ROOT_DIR)/libs/libft
MINILIBX_DIR = $(ROOT_DIR)/libs/mlx

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
FRAMEWORKS = -framework OpenGL -framework AppKit
LIBRARY = -lmlx -lft

INCS = ./inc
SRCS = ./srcs/*.c ./srcs/read/*.c ./srcs/draw/*.c
LIBS = ./libs

NAME = cub3D

all: ${NAME}

${NAME}:
	@echo "Compile library..."
	@make -C ${LIBFT_DIR}
	@make -C ${MINILIBX_DIR}
	@${CC} ${CFLAGS} -I${INCS} -L${LIBFT_DIR} -L${MINILIBX_DIR} ${LIBRARY} ${FRAMEWORKS} ${SRCS} -o ${NAME}
	@echo "Successfully complied ./$(NAME)"

clean:
	@${RM} ${LIBFT_DIR}/*.o
	@${RM} ${MINILIBX_DIR}/*.o
	@echo "Successfully delete library obj files"

fclean: clean
	@${RM} ${LIBFT_DIR}/*.a
	@${RM} ${MINILIBX_DIR}/*.a
	@${RM} ${PRINTF_DIR}/*.a
	@${RM} ${NAME}
	@echo "Successfully delete ./$(NAME) and library files"

re: fclean all

test:
	@${CC} ${CFLAGS} -I${INCS} -L${LIBFT_DIR} -L${MINILIBX_DIR} ${LIBRARY} ${FRAMEWORKS} ${SRCS} -o ${NAME}
	@echo "Successfully complied ./$(NAME)"

.PHONY: all clean fclean re