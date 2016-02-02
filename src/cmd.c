/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 17:16:08 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 16:45:40 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "sh42.h"
#include "libft.h"
#include "builtin.h"
#include "error.h"

char				*ft_get_fullpath_cmd(t_cmd *cmd)
{
	char			*fullpath;

	fullpath = NULL;
	if ((fullpath = ft_get_in_path_env(cmd)))
		return (fullpath);
	else if ((fullpath = ft_get_in_absolute_path(cmd)))
		return (fullpath);
	ft_cmdnotfound(cmd);
	return (NULL);
}

char				*ft_get_in_path_env(t_cmd *cmd)
{
	char			**bin_path;
	int				i;
	char			*fullpath;
	char			*envpath;

	if ((envpath = ft_getenv(*cmd->envp, "PATH")))
	{
		if (!((bin_path = ft_strsplit(envpath, ':'))))
			ft_error(ERR_MALLOC);
		i = 0;
		while (bin_path[i])
		{
			if ((fullpath = ft_cmdexist(bin_path[i], cmd->cmd)))
			{
				ft_strtabfree(&bin_path);
				return (fullpath);
			}
			free(fullpath);
			i++;
		}
		ft_strtabfree(&bin_path);
	}
	return (NULL);
}

char				*ft_get_in_absolute_path(t_cmd *cmd)
{
	char			*tmp;

	tmp = ft_getenv(*cmd->envp, "PWD");
	if (cmd->cmd[0] == '/' && access(cmd->cmd, F_OK) == 0)
		return (ft_strdup(cmd->cmd));
	else if (tmp && ft_strnequ(cmd->cmd, "./", 2))
		return (ft_catpath(ft_getenv(*cmd->envp, "PWD"), &cmd->cmd[2]));
	else
		return (NULL);
}

void				ft_cmdnotfound(t_cmd *cmd)
{
	ft_putstr_fd("42sh: command not found: ", 2);
	ft_putendl_fd(cmd->cmd, 2);
}

char				*ft_cmdexist(char *path, char *cmd)
{
	char	*fullpath;

	fullpath = ft_catpath(path, cmd);
	if (!access(fullpath, F_OK | X_OK))
		return (fullpath);
	return (NULL);
}
