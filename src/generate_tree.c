/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 21:32:39 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/26 18:19:02 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_node		*create_root(t_node *left, t_node *right, t_type_node type)
{
	t_node	*root;

	root = ft_btinitnode_syntax(NULL, type);
	root->left = left;
	root->right = right;
	return (root);
}

t_node		*generate_pipe(t_arg_parse *arg)
{
	t_node	*newe_cmd;

	newe_cmd = ft_btinitnode_syntax(arg->cmd, TN_CMD);
	if (arg->pipeline == NULL)
	{
		arg->pipeline = newe_cmd;
		arg->cmd = NULL;
		return (arg->pipeline);
	}
	arg->pipeline = create_root(arg->pipeline, newe_cmd, TN_PIPE);
	arg->cmd = NULL;
	return (arg->pipeline);
}

t_node		*generate_boolline(t_arg_parse *arg, t_token_type tok_type)
{
	if (arg->boolline == NULL)
	{
		arg->boolline = arg->pipeline;
		arg->pipeline = NULL;
		return (arg->boolline);
	}
	if (tok_type == T_AND)
		arg->boolline = create_root(arg->boolline, arg->pipeline, TN_AND);
	else if (tok_type == T_OR)
		arg->boolline = create_root(arg->boolline, arg->pipeline, TN_OR);
	arg->pipeline = NULL;
	return (arg->boolline);
}

t_node		*generate_semicol(t_arg_parse *arg)
{
	if (arg->tree == NULL)
	{
		arg->tree = arg->boolline;
		arg->boolline = NULL;
		return (arg->tree);
	}
	arg->tree = create_root(arg->tree, arg->boolline, TN_SEMICOL);
	arg->boolline = NULL;
	return (arg->tree);
}

t_node		*ft_btinitnode_syntax(void *data, t_type_node type)
{
	t_node	*newe;

	newe = ft_btinitnode(data);
	newe->type = type;
	return (newe);
}
