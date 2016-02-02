/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:45:21 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 17:27:46 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "sh42.h"
#include "builtin.h"
#include "libft.h"
#include "shell_options.h"
#include "error.h"

static char		*ft_get_cd_path(t_options *options, t_cmd *cmd, int i)
{
	char		*tmp;

	tmp = NULL;
	if (ft_optisset(options, '-') && (tmp = ft_getenv(*cmd->envp, "OLDPWD")))
		return (ft_strdup(tmp));
	else if (!cmd->args[i])
	{
		if ((tmp = ft_getenv(*cmd->envp, "HOME")) && !ft_strequ(tmp, ""))
			ft_strtabadd(&cmd->args, ft_strdup(tmp));
		else
			return (NULL);
	}
	if (cmd->args[i][0] == '/')
		return (ft_strdup(cmd->args[i]));
	else
		return (ft_check_in_cdpath(cmd->args[i], *cmd->envp));
}

void			ft_cd(t_cmd *cmd)
{
	char		*path;
	char		*tmp;
	int			i;
	t_options	*options;

	path = NULL;
	i = 1;
	options = ft_getcdoptions();
	i += ft_set_cd_options(options, &cmd->args[1]);
	path = ft_get_cd_path(options, cmd, i);
	if (path)
	{
		if (ft_optisset(options, 'P'))
			ft_replace_link(&path);
		tmp = path;
		ft_path_canonize(&path);
		ft_change_pwd(path, cmd);
		free(tmp);
	}
	ft_optfree(options);
}

int				ft_change_pwd(char *path, t_cmd *cmd)
{
	struct stat	infos;
	int			error;
	int			ret;

	error = 0;
	ret = 0;
	ret = stat(path, &infos);
	if (access(path, F_OK) != 0)
		error = NOTEXIST;
	else if (!(S_IFDIR == (infos.st_mode & S_IFMT)))
		error = NOTDIR;
	else if (access(path, X_OK) != 0)
		error = NOTACCESS;
	if (ret == -1 && !error)
		error = UNDEF;
	if (error)
		ft_put_error(error, cmd->args[1]);
	else
	{
		ft_update_env(cmd->envp, "OLDPWD", ft_getenv(*cmd->envp, "PWD"));
		ft_update_env(cmd->envp, "PWD", path);
		error = chdir(path);
	}
	free(path);
	return (error != 0);
}

t_options		*ft_getcdoptions(void)
{
	t_options	*options;

	options = ft_optinit(3);
	ft_optadd(options, ft_optcreate('P'));
	ft_optadd(options, ft_optcreate('L'));
	ft_optadd(options, ft_optcreate('-'));
	return (options);
}

char			*ft_catpath(char *path_l, char *path_r)
{
	int			len;
	char		*fullpath;

	len = 1 + ft_strlen(path_l) + ft_strlen(path_r);
	if (!((fullpath = ft_strnew(len))))
		ft_error(ERR_MALLOC);
	ft_strcpy(fullpath, path_l);
	ft_strcat(fullpath, "/");
	ft_strcat(fullpath, path_r);
	return (fullpath);
}
