# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 11:43:35 by jkoskela          #+#    #+#              #
#    Updated: 2020/12/14 14:24:26 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

# src / obj files
SRC		=	main.c \
			mtx_new.c \
			mtx_tests.c \
			identity.c \
			m_dot.c \
			m_rad.c \
			m_dgr.c \
			mtx_vtx.c \
			mtx_cpy.c \
			p_dbl_arr.c \
			mtx_get_col.c \
			projection.c \
			mtx_get_row.c \
			mtx_multiply.c \
			rot_x.c \
			rot_y.c \
			rot_z.c \
			mtx_print.c \
			input_parse.c \
			p_map.c \
			vtx_new.c \
			translation.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# mlx library
MLX		= ./minilibx/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I /usr/X11/include -g
MLX_LNK	= -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./inc/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out.dSYM
	make -C $(FT) fclean

re: fclean all