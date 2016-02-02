/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 17:42:18 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 16:44:12 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "builtin.h"
#include "libft.h"

void			ft_env(t_cmd *cmd)
{
	char		**cpy_env;
	int			i;
	t_cmd		*pseudo_cmd;

	i = 1;
	cpy_env = ft_get_envp_cpy(cmd, &i);
	if (!cmd->args[i])
		ft_strtabput(cpy_env);
	else
	{
		pseudo_cmd = ft_cmd_init(&cmd->args[i], &cpy_env);
		ft_exec_cmd(pseudo_cmd);
		ft_freecmd(&pseudo_cmd);
	}
	ft_strtabfree(&cpy_env);
}

char			**ft_get_envp_cpy(t_cmd *cmd, int *i)
{
	char		**cpy_env;
	char		*value;
	char		*name;
	int			cnt;
	t_options	*options;

	options = ft_optinit(1);
	ft_optadd(options, ft_optcreate('i'));
	*i += ft_setoptions(options, &cmd->args[1]);
	if (!ft_optisset(options, 'i'))
		cpy_env = ft_strtabcpy(*(cmd->envp));
	else
		cpy_env = ft_strtabinit(0);
	while (cmd->args[*i] && (value = ft_strchr(cmd->args[*i], '=')))
	{
		cnt = 0;
		while (cmd->args[*i][cnt] != '=')
			cnt++;
		name = ft_strsub(cmd->args[*i], 0, cnt);
		ft_update_env(&cpy_env, name, ++value);
		free(name);
		++(*i);
	}
	ft_optfree(options);
	return (cpy_env);
}

char			*ft_getenv(char **envp, char *get)
{
	int			i;
	int			len;

	len = ft_strlen(get);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(get, envp[i], len) && envp[i][len] == '=')
			return (&(envp[i][len + 1]));
		i++;
	}
	return (NULL);
}

void			ft_setenv(t_cmd *cmd)
{
	if (!cmd->args[1])
		return (ft_env(cmd));
	ft_update_env(cmd->envp, cmd->args[1], cmd->args[2]);
}

void			ft_unsetenv(t_cmd *cmd)
{
	int			index;
	int			i;

	if (!cmd->args[1])
	{
		ft_putendl("unsetenv: argument is missing");
		return ;
	}
	i = 1;
	while (cmd->args[i])
	{
		if (ft_strequ(cmd->args[i], "*"))
		{
			while ((*(cmd->envp))[0])
				ft_strtabrm(cmd->envp, 0);
			return ;
		}
		index = ft_getenvindex(*(cmd->envp), cmd->args[i]);
		if (index > -1)
			ft_strtabrm(cmd->envp, index);
		++i;
	}
}
