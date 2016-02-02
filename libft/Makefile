# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfrey <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/30 11:03:46 by rfrey             #+#    #+#              #
#    Updated: 2014/03/27 19:28:53 by rfrey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
PATH_INC = includes
PATH_OBJ = obj
PATH_SRC = src
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memcat.c\
ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_listclear.c ft_listcreate.c ft_listpop.c ft_listpushback.c \
ft_listcnt.c ft_listpushfront.c ft_get_next_line.c \
ft_listgetn.c ft_strtabcpy.c ft_strtabfree.c ft_strtabsize.c ft_strtabput.c \
ft_strtabadd.c ft_strtabrm.c ft_listpoplast.c ft_listpop_n.c ft_strtabinit.c \
ft_printf.c pf_convert.c pf_get_format.c pf_init.c pf_output.c \
pf_parse.c pf_tools.c pf_type_format.c ft_strdelchar.c

OBJ = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rc $@ $(OBJ)
	@ranlib $(NAME)
	@echo " done !"

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c)
	@echo -n .
	@mkdir -p $(PATH_OBJ)
	@$(CC) $(CFLAGS) -o $@ -c $^ -I $(PATH_INC)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re
