# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/30 11:03:46 by rfrey             #+#    #+#              #
#    Updated: 2014/03/27 19:29:02 by rfrey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = 42sh
PATH_OBJ = obj
PATH_SRC = src
PATH_INC = inc
PATH_LIBFT = libft
LIBFT = libft.a
PATH_LIBFT_INC = $(PATH_LIBFT)/includes

SRC = main.c builtin.c builtin_exit.c builtin_env.c builtin_cd.c \
		cmd_init.c cmd.c shell_options.c shell_options_ext.c canonize.c \
		builtin_env_tools.c lexer.c lexer2.c cmd_exec.c error.c \
		term_init.c read.c cmd_line.c historic.c line_edit.c line_move.c \
		clipboard.c signal.c selection.c selection2.c line_move2.c \
		parse.c parse2.c parse_rule.c parse_rule_cmd.c tree.c \
		check_quote.c build_cmd.c generate_tree.c resolve_tree.c \
		resolve_tree_cmd.c redir.c builtin_echo.c global.c builtin_cd2.c \
		completion.c completion2.c completion3.c completion4.c

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

all : $(NAME)

$(NAME) : $(PATH_LIBFT)/$(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(PATH_LIBFT)/$(LIBFT) -ltermcap -o $@
	@echo " done !"

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c)
	@echo -n .
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(PATH_INC)/ -I $(PATH_LIBFT_INC)/

$(PATH_LIBFT)/$(LIBFT) : $(PATH_LIBFT)/Makefile
	@cd $(PATH_LIBFT)/ && $(MAKE)

clean :
	@rm -f $(OBJ)
	@cd $(PATH_LIBFT) && $(MAKE) $@

fclean : clean
	@rm -f $(NAME)
	@rm -f $(PATH_LIBFT)/$(LIBFT)

re : fclean all

.PHONY: clean fclean
