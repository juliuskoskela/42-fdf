NAME		=	fdf

SRC_LIST	=	main.c \
				allocate_buffer.c \
				destroy_buffer.c \
				process_buffer.c \
				print_buffer.c \
				add_model.c \
				draw_line.c \
				create_model.c \
				create_camera.c \
				create_world.c \
				world_from_model.c \
				view_from_world.c \
				clip_from_view.c \
				window_from_clip.c \
				grid_triangulation.c \
				parse_file.c \
				loop_callback.c \
				key_callback.c \
				get_mesh_dimensions.c \

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/
MLX_DIR		=	minilibx-linux/
LIB_DIR		=	libft/
LIBFT_A		=	$(LIB_DIR)libft.a
USR_INC		=	/usr/include
INC_DIRS	=	$(LIB_DIR) $(USR_INC) $(MLX_DIR) $(SRC_DIR)
USR_LIB		=	/usr/lib
MLX_A		=	$(MLX_DIR)libmlx.a

INC			=	$(addprefix $(INC_DIR), fdf.h)
SRC			=	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ			=	$(SRC:$(SRC_DIR)%=$(OBJ_DIR)%.o)
RM			=	/bin/rm -rf
CC			=	clang
FSANA		=	-fsanitize=address
FSANL		=	-fsanitize=leak
FSANU		=	-fsanitize=undefined
CFLAGS		=	-Wall -Wextra -Werror -O3
INCLUDES	=	$(addprefix -I,$(INC_DIRS))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ): | $(OBJ_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)% $(INC)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT_A):
	make -C $(LIB_DIR)

$(MLX_A):
	make -C $(MLX_DIR)

$(NAME): $(LIBFT_A) $(MLX_A) $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L$(USR_LIB) -Llibft/ -lft -Imlx_linux -lpthread -lXext -lX11 -lm -lz -o $@

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RM) $(OBJ_DIR)

clean: cleanobjdir
	make -C $(MLX_DIR) clean
	make -C $(LIB_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_A)

re: fclean all
