# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 22:32:30 by jkoskela          #+#    #+#              #
#    Updated: 2020/12/06 06:26:53 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		inc/ft_printf.a
LIBFT_A =	libft/libft.a
COMP =		gcc -g -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
PRINTF_H =	-I inc/
LIBFT_H = 	-I libft/
OBJ_DIR =	obj/
SRC_DIR =	src/
LIB_DIR =	libft/
CFILE =		ft_printf.c \
			convert.c \

CFIND =		$(CFILE:%=$(SRC_DIR)%)
OFILE =		$(CFILE:%.c=%.o)
OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
		@make -C $(LIB_DIR)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@printf "\r\033[38;5;117m✓ MAKE ft_printf.a\033[0m\033[K\n"

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

t: all
		@mv tests.tests tests
		@gcc -g -o test.a tests/tests_printf.c libft/libft.a inc/ft_printf.a
		@printf "\r\033[38;5;117m✓ MAKE test\033[0m\033[K\n"
		@mv tests tests.tests
		@./test.a
clean:
		@rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@printf "\r\033[38;5;202m✗ clean $(NAME).\033[0m\033[K\n";

fclean: clean
		@rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@printf "\r\033[38;5;196m✗ fclean $(NAME).\033[0m\033[K\n";

tclean: fclean
		@rm -rf *.dSYM
		@rm -f test.a
		@rm -rf .vscode

re: clean all

.PHONY: all clean flcean re
