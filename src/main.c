/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:26:36 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/27 18:17:59 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "lexer.h"
#include "builtin.h"
#include "libft.h"
#include "list.h"
#include "ft_term.h"
#include "parse.h"

int			main(int argc, char **argv, char **envp)
{
	if (argc && argv && envp)
	{
		envp = get_envp(envp);
		ft_exec(&envp);
	}
	return (0);
}

void		ft_exec(char ***envp)
{
	char	*line;
	t_list	*tokens;
	char	*trim;

	line = NULL;
	tokens = NULL;
	ft_prompt(*envp);
	line = ft_get_cmd(*envp);
	if (!line)
		return (ft_exec(envp));
	trim = ft_strtrim(line);
	if (trim && !ft_strequ(trim, ""))
	{
		tokens = ft_tokenize(trim);
		free(trim);
		if (tokens)
			parse_cmd(tokens, envp);
	}
	return (ft_exec(envp));
}

void		ft_prompt(char **envp)
{
	char	*pwd;
	char	*home;
	char	*user;
	int		len;

	if ((user = ft_getenv(envp, "USER")))
	{
		ft_putstr(user);
		ft_putstr(":");
	}
	pwd = ft_getenv(envp, "PWD");
	home = ft_getenv(envp, "HOME");
	if (pwd && home)
	{
		len = ft_strlen(home);
		if (ft_strnequ(pwd, home, len))
		{
			ft_putstr("~");
			ft_putstr(&pwd[len]);
		}
		else
			ft_putstr(pwd);
	}
	envp++;
	ft_putstr("> ");
}
