/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 23:10:24 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/11 23:05:54 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh42.h"
#include "builtin.h"

void		ft_exec_cmd(t_cmd *cmd)
{
	if (!ft_exec_builtin(cmd))
	{
		cmd->fullpath = ft_get_fullpath_cmd(cmd);
		execve(cmd->fullpath, cmd->args, *(cmd->envp));
	}
	exit(EXIT_FAILURE);
}
