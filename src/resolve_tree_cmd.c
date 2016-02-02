/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tree_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 20:04:30 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/21 19:10:01 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "sh42.h"
#include "parse.h"
#include "exec.h"
#include "error.h"

void	resolve_cmd_child(t_node *node, int *fd_read, int is_end, int pip[2])
{
	if (*fd_read != STDIN_FILENO)
		dup2(*fd_read, STDIN_FILENO);
	if (!is_end)
	{
		close(pip[OUT]);
		dup2(pip[IN], STDOUT_FILENO);
		close(pip[IN]);
	}
	if (ft_resolve_redir((t_cmd*)(node->data)) != -1)
		ft_exec_cmd((t_cmd*)(node->data));
	exit(1);
}

int		resolve_cmd_parent(int is_end, int pip[2], int pid)
{
	int		ret;

	if (!is_end)
		close(pip[IN]);
	waitpid(pid, &ret, 0);
	if (WIFEXITED(ret))
		ret = WEXITSTATUS(ret);
	else
		ret = 1;
	return (ret);
}

int		ft_resolve_cmd_nofork(t_cmd *cmd)
{
	if (ft_resolve_redir(cmd) != -1)
	{
		if (ft_exec_builtin(cmd))
			return (0);
	}
	return (1);
}

int		resolve_cmd(t_node *node, int *fd_read, int is_end)
{
	pid_t	pid;
	int		pip[2];
	int		ret;

	if (!is_end)
	{
		if (pipe(pip))
			ft_error(ERR_PIPE);
	}
	pid = fork();
	if (pid > 0)
	{
		*(get_pid_running_proc()) = pid;
		ret = resolve_cmd_parent(is_end, pip, pid);
		*(get_pid_running_proc()) = 0;
		*fd_read = pip[OUT];
		return (ret);
	}
	else if (pid == 0)
		resolve_cmd_child(node, fd_read, is_end, pip);
	else
		ft_error(ERR_FORK);
	return (0);
}
