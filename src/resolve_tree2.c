/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tree2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:45:37 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/11 22:51:56 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "parse.h"
#include "exec.h"
#include "error.h"

void	ft_resolve_tree(t_node *tree)
{
	pid_t	pid;
	int		fd_read;

	pid = fork();
	fd_read = STDIN_FILENO;
	if (pid > 0)
		wait(NULL);
	else if (pid == 0)
		ft_browse_tree(tree, &fd_read, 1);
	else
		ft_error(ERR_FORK);
}

int		resolve_semicol(t_node *node, int *fd_read)
{
	int		ret;

	ret = 0;
	if (node != NULL && node->left != NULL)
		ret = ft_browse_tree(node->left, fd_read, 1);
	if (node != NULL && node->left != NULL)
		ret = ft_browse_tree(node->right, fd_read, 1);
	return (ret);
}

int		browse_right(int ret, t_type_node type)
{
	if (ret != 0 && type == TN_AND)
		return (0);
	if (ret == 0 && type == TN_OR)
		return (0);
	return (1);
}

int		ft_browse_tree(t_node *node, int *fd_read, int first_pipe)
{
	int		ret;
	char	*line;

	line = NULL;
	if (node->left != NULL)
		ret = ft_browse_tree(node->left, fd_read, !(node->type == TN_PIPE));
	if (node->type == TN_SEMICOL)
		return (resolve_semicol(node, fd_read));
	if (node->type == TN_CMD)
		return (resolve_cmd(node, fd_read, first_pipe));
	if (browse_right(ret, node->type) && node->right != NULL)
		ret = ft_browse_tree(node->right, fd_read,
			(first_pipe || node->type == TN_AND || node->type == TN_OR));
	return (ret);
}
