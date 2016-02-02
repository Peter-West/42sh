/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 23:50:13 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/21 19:01:09 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "lexer.h"
#include "libft.h"
#include "error.h"

int			ft_syn_error(int token_type)
{
	ft_putstr_fd("Syntax error near '", 2);
	if (token_type == T_PIPE)
		ft_putstr_fd("|", 2);
	else if (token_type == T_SEMICOLON)
		ft_putstr_fd(";", 2);
	else if (token_type == T_REDIR_LEFT)
		ft_putstr_fd("<", 2);
	else if (token_type == T_REDIR_RIGHT_1)
		ft_putstr_fd(">", 2);
	else if (token_type == T_REDIR_RIGHT_2)
		ft_putstr_fd(">>", 2);
	else if (token_type == T_EOS)
		ft_putstr_fd("EOS", 2);
	else
		ft_putstr_fd("unknow", 2);
	ft_putendl("'");
	return (-1);
}

void		ft_error(char *error)
{
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void		ft_put_error(int error, char *str)
{
	if (!str)
		str = "";
	else if (error == NOTDIR)
		ft_printf("cd: not a directory: %s\n", str);
	else if (error == NOTEXIST)
		ft_printf("cd: no such file or directory: %s\n", str);
	else if (error == NOTACCESS)
		ft_printf("cd: permission denied: %s\n", str);
	else if (error == ISDIR)
		ft_printf("cd: is a directory: %s\n", str);
}

void		ft_puterror(char *mes, char *param)
{
	if (!mes)
		mes = ERR_UNDEF;
	if (!param)
		param = "";
	ft_putstr_fd("42sh: ", 2);
	ft_putstr_fd(param, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(mes, 2);
}

void		ft_file_error(int error, char *str)
{
	if (!str)
		str = "";
	else if (error == NOTDIR)
		ft_putstr_fd("42sh: not a directory: ", 2);
	else if (error == NOTEXIST)
		ft_putstr_fd("42sh: no such file or directory: ", 2);
	else if (error == NOTACCESS)
		ft_putstr_fd("42sh: permission denied: ", 2);
	else if (error == ISDIR)
		ft_putstr_fd("42sh: is a directory: ", 2);
	else if (error == UNDEF)
		ft_putstr_fd("42sh: cannot access file ", 2);
	ft_putendl_fd(str, 2);
}
