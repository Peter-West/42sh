/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 20:47:59 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/26 17:31:57 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh42.h"
#include "error.h"
#include "builtin.h"
#include "libft.h"

int				ft_set_cd_options(t_options *options, char **args)
{
	int			i;
	int			j;

	i = 0;
	while (args[i] && args[i][0] == '-')
	{
		j = 1;
		if (!args[i][j])
			ft_optset(options, '-');
		while (args[i][j])
		{
			if (args[i][j] == 'P' && ft_optisset(options, 'L'))
				ft_optunset(options, 'L');
			else if (args[i][j] == 'L' && ft_optisset(options, 'P'))
				ft_optunset(options, 'P');
			ft_optset(options, args[i][j]);
			j++;
		}
		i++;
	}
	return (i);
}

static char		*ft_get_new_path(char *path, char **split)
{
	int			len;
	int			i;
	char		*ret;

	i = 0;
	len = (path[0] == '/');
	while (split[i])
	{
		len += ft_strlen(split[i]);
		++i;
	}
	if ((!(ret = ft_strnew(len + ft_strtabsize(split) + 1))))
		ft_error(ERR_MALLOC);
	i = 0;
	if (path[0] == '/')
		ret[0] = '/';
	while (split[i])
	{
		ft_strcat(ret, split[i]);
		if (split[i + 1])
			ft_strcat(ret, "/");
		++i;
	}
	ft_strtabfree(&split);
	return (ret);
}

void			ft_replace_link(char **path)
{
	char		**split;
	int			i;
	char		*tmp;
	char		buf[2049];

	ft_bzero(&buf, 2049);
	split = ft_strsplit(*path, '/');
	i = 0;
	while (split[i])
	{
		if (!ft_strequ(split[i], ".") && !ft_strequ(split[i], "..")
			&& readlink(split[i], buf, 2048) != -1)
		{
			tmp = split[i];
			split[i] = ft_strdup(buf);
			free(tmp);
		}
		++i;
	}
	tmp = *path;
	*path = ft_get_new_path(*path, split);
	free(tmp);
}

static char		*ft_check_in_cdpath2(char *curpath, char **envp)
{
	char	**split;
	int		i;
	char	*tmp;
	char	*cdpath;

	if ((!(cdpath = ft_getenv(envp, "CDPATH"))))
		return (NULL);
	split = ft_strsplit(cdpath, ':');
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		tmp = ft_catpath(split[i], curpath);
		if (!access(tmp, F_OK))
			return (tmp);
		else
			free(tmp);
		++i;
	}
	ft_strtabfree(&split);
	return (NULL);
}

char			*ft_check_in_cdpath(char *curpath, char **envp)
{
	char	*cdpath;
	char	*pwd;
	char	*tmp;

	pwd = ft_getenv(envp, "PWD");
	cdpath = ft_getenv(envp, "CDPATH");
	if (!cdpath || curpath[0] == '.')
	{
		if (!pwd)
			return (NULL);
		else
			return (ft_catpath(pwd, curpath));
	}
	else
	{
		tmp = ft_catpath(pwd, curpath);
		if (!access(tmp, F_OK))
			return (tmp);
		else
		{
			free(tmp);
			return (ft_check_in_cdpath2(curpath, envp));
		}
	}
}
