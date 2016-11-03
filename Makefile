NAME =		fractol
COMP =		gcc
SRC_DIR =	srcs
SRC =		$(SRC_DIR)/burningship.c \
			$(SRC_DIR)/color.c \
			$(SRC_DIR)/draw.c \
			$(SRC_DIR)/env.c \
			$(SRC_DIR)/fractal.c \
			$(SRC_DIR)/fractol.c \
			$(SRC_DIR)/hsv_to_rgb.c \
			$(SRC_DIR)/julia.c \
			$(SRC_DIR)/mandelbrot.c \
			$(SRC_DIR)/memory.c \
			$(SRC_DIR)/mouse.c \
			$(SRC_DIR)/move.c
OBJ =		$(SRC:.c=.o)
INC =		-I includes
LFT =		-Llibft -lft
LMLX =		-Lmlx -lmlx
LIB =		$(LFT) $(LMLX)
GRAPH =		-framework OpenGL -framework AppKit
FLAGS =		-Wall -Wextra -Werror
DEBUG = 	-g

$(NAME):	$(OBJ)
		make -C libft/
		make -C mlx/
		$(COMP) -o $(NAME) $(OBJ) $(LIB) $(GRAPH)

debug:		$(OBJ)
		make -C libft/
		make -C mlx/
		$(COMP) -o $(NAME) $(OBJ) $(LIB) $(GRAPH) $(DEBUG)

all:		$(NAME)

clean:
		make clean -C libft/
		make clean -C mlx/
		rm -f $(OBJ)

fclean:		clean
		make fclean -C libft/
		make clean -C mlx/
		rm -f $(NAME)

re:			fclean all

norme:
		norminette libft/*.c
		norminette libft/includes/*.h
		norminette srcs/*.c
		norminette includes/*.h

%.o:		%.c
		$(COMP) -c $(INC) $(FLAGS) $^ -o $@