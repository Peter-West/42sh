/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 16:45:37 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/21 17:36:47 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"
#include "parse.h"
#include "exec.h"
#include "error.h"

int		ft_resolve_tree(t_node *tree)
{
	int		fd_read;

	fd_read = 0;
	return (ft_browse_tree(tree, &fd_read, 1, 0));
}

int		resolve_semicol(t_node *node, int *fd_read, int pl)
{
	int		ret;

	ret = 0;
	if (node != NULL && node->left != NULL)
		ret = ft_browse_tree(node->left, fd_read, 1, pl);
	if (node != NULL && node->left != NULL)
		ret = ft_browse_tree(node->right, fd_read, 1, pl);
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

int		ft_browse_tree(t_node *node, int *fd_rd, int first_pipe, int pl)
{
	int		ret;

	ret = 0;
	if (node->type == TN_PIPE)
		pl = 1;
	if (node->type == TN_SEMICOL)
		return (resolve_semicol(node, fd_rd, pl));
	if (node->left != NULL)
		ret = ft_browse_tree(node->left, fd_rd, !(node->type == TN_PIPE), pl);
	if (node->type == TN_CMD)
	{
		if (!pl && ft_is_builtin(((t_cmd*)(node->data))))
			return (ft_resolve_cmd_nofork(((t_cmd*)(node->data))));
		return (resolve_cmd(node, fd_rd, first_pipe));
	}
	if (browse_right(ret, node->type) && node->right != NULL)
		ret = ft_browse_tree(node->right, fd_rd,
			(first_pipe || node->type == TN_AND || node->type == TN_OR), pl);
	if (node->type == TN_PIPE)
		pl = 0;
	return (ret);
}
