# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/21 17:29:30 by esukava           #+#    #+#              #
#    Updated: 2020/12/04 02:20:44 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB= libft/libft.a
NAME = fdf
SRCS =	src/main.c \
		src/g_vector.c \
		src/g_vertex.c \
		src/g_vct_add.c \
		scr/g_vct_sub.c \
		src/g_vct_mag.c \
		src/g_vct_nor.c \

OBJS = $(SRCS:.c=.o)
DEBUG = $(NAME).dSYM

.PHONY: all clean fclean re

all: $(NAME)

clean:
ifneq (,$(wildcard $(NAME).dSYM))
	@rm -r $(DEBUG)
	@echo "Deleted $(NAME).dSYM in $(NAME)"
endif
	@make -C libft clean
	@rm -f $(OBJS)
	@echo "Deleted all .o files!"

fclean:
	@make -C libft fclean
	@rm -f $(OBJS)
	@rm -f $(NAME)
	rm -rf
	@echo "Deleted all .o files!"
ifneq (,$(wildcard .DS_Store))
	@rm -r .DS_Store
	@echo "Deleted .DS_Store in $(NAME)"
endif
ifneq (,$(wildcard $(NAME).dSYM))
	@rm -r $(DEBUG)
	@echo "Deleted $(NAME).dSYM in $(NAME)"
endif

re: fclean all

l:
	@make -C libft
d:
	@gcc -g -Wall -Wextra -Werror $(SRCS) $(LIBFT) -lmlx -framework OpenGL \
	-framework AppKit -o $(NAME)
	@echo "Lldb debug folder"
	@echo "Compilation of $(NAME) successful!"

$(NAME): $(OBJS)
	@make -C libft
	@gcc -Wall -Wextra -Werror $^ $(LIBFT) -I /usr/X11/include -g -L \
	/usr/X11/lib -l mlx -framework OpenGL -framework AppKit
	@mv a.out fdf
	@echo "Compilation of $(NAME) successful!"

%.o: %.c
	@gcc -c -Wall -Wextra -Werror -o $@ $<
