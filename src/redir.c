/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 23:13:25 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/21 19:03:11 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "sh42.h"
#include "exec.h"
#include "error.h"

int		ft_open_for_reading(char *filename, struct stat *infos)
{
	if (access(filename, F_OK))
		return (NOTEXIST);
	else if (access(filename, R_OK))
		return (NOTACCESS);
	else if ((S_IFDIR == (infos->st_mode & S_IFMT)))
		return (ISDIR);
	return (0);
}

int		ft_open_for_writing(char *filename, struct stat *infos)
{
	if (access(filename, W_OK))
		return (NOTACCESS);
	else if ((S_IFDIR == (infos->st_mode & S_IFMT)))
		return (ISDIR);
	return (0);
}

int		ft_open_file(char *filename, int mode)
{
	struct stat	infos;
	int			error;
	int			ret;

	ret = 0;
	error = 0;
	ret = stat(filename, &infos);
	if (mode & O_WRONLY && !access(filename, F_OK))
		error = ft_open_for_writing(filename, &infos);
	else if (!(mode & O_WRONLY))
		error = ft_open_for_reading(filename, &infos);
	if (ret == -1 && !error)
		error = UNDEF;
	if (error)
	{
		ft_file_error(error, filename);
		return (-1);
	}
	return (open(filename, mode));
}

int		ft_resolve_redir(t_cmd *cmd)
{
	int		i;
	int		fd;

	fd = 0;
	i = 0;
	while (cmd->redir[i])
	{
		if (fd)
			close(fd);
		fd = ft_resolve_redir2(cmd, i);
		if (fd == -1)
			return (fd);
		++i;
	}
	if (fd)
		close(fd);
	return (fd);
}

int		ft_resolve_redir2(t_cmd *cmd, int i)
{
	int		fd;

	fd = 0;
	if (cmd->redir[i]->type == RED_LEFT_1)
	{
		if ((fd = ft_open_file(cmd->redir[i]->filename, O_RDONLY)) != -1)
			dup2(fd, STDIN_FILENO);
	}
	else
	{
		if (cmd->redir[i]->type == RED_RIGHT_1)
			fd = ft_open_file(cmd->redir[i]->filename, MOD_RED_R1);
		else if (cmd->redir[i]->type == RED_RIGHT_2)
			fd = ft_open_file(cmd->redir[i]->filename, MOD_RED_R2);
		if (fd != -1)
			dup2(fd, STDOUT_FILENO);
	}
	return (fd);
}
