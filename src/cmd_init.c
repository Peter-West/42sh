/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 22:02:56 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/11 23:06:14 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "libft.h"
#include "error.h"

t_cmd		*ft_cmd_init(char **args, char ***envp)
{
	t_cmd	*cmd;

	cmd = ft_create_cmd(envp);
	free(cmd->args);
	cmd->args = args;
	cmd->cmd = cmd->args[0];
	return (cmd);
}

void		ft_free_redir(t_redir *redir)
{
	free(redir->filename);
	free(redir);
}

void		ft_freecmd(t_cmd **cmd)
{
	int		i;

	i = 0;
	while ((*cmd)->redir[i])
	{
		ft_free_redir((*cmd)->redir[i]);
		++i;
	}
	free((*cmd)->redir);
	ft_strtabfree(&((*cmd)->args));
	if ((*cmd)->fullpath)
		free((*cmd)->fullpath);
	free(*cmd);
	*cmd = NULL;
}

t_redir		*ft_init_redir(char *filename, t_redir_type type)
{
	t_redir	*redir;

	if ((!(redir = (t_redir*)malloc(sizeof(t_redir)))))
		ft_error(ERR_MALLOC);
	if ((!(redir->filename = ft_strdup(filename))))
		ft_error(ERR_MALLOC);
	redir->type = type;
	return (redir);
}

t_cmd		*ft_create_cmd(char ***envp)
{
	t_cmd	*cmd;

	if ((!(cmd = (t_cmd *)malloc(sizeof(t_cmd)))))
		ft_error(ERR_MALLOC);
	cmd->cmd = NULL;
	cmd->envp = envp;
	if ((!(cmd->args = (char**)malloc(sizeof(char*)))))
		ft_error(ERR_MALLOC);
	cmd->args[0] = NULL;
	if ((!(cmd->redir = (t_redir**)malloc(sizeof(t_redir*)))))
		ft_error(ERR_MALLOC);
	cmd->redir[0] = NULL;
	cmd->fullpath = NULL;
	return (cmd);
}
