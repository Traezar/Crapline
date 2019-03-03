# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 08:38:15 by rsathiad          #+#    #+#              #
#    Updated: 2019/01/27 14:55:07 by rsathiad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = line_edit
OBJ = *.o

SRC = line_srcs/line.c line_srcs/stdin_handler.c  line_srcs/prompt.c line_srcs/quote.c line_srcs/cursor.c \
	line_srcs/screen.c line_srcs/display_util.c line_srcs/term_arrow.c line_srcs/error.c line_srcs/process_input.c
HDR = line_includes/line.h 

all:libft_lib select

libft_lib:
	@make -C libft
select:
	@gcc -o $(NAME) $(CFLAGS) $(SRC) -I $(HDR) -L libft -lft -ltermcap
	@echo "\033[1;32m[Compiled]\033[0m: \033[1;33m./line_edit\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[1;31m[Removed]\033[0m: select object files"

fclean: clean
	@clear
	@rm -rf ft_select
	@cd libft && make fclean

re: fclean all

CFLAGS = -Wall -Werror -Wextra

PHONY:
	clean fclean all re libft
