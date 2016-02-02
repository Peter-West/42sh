/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 00:22:08 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/27 19:19:58 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list.h>
#include "builtin.h"
#include "parse.h"
#include "exec.h"
#include "ft_term.h"
#include "sh42.h"

t_node	**ft_get_tree(t_node *set)
{
	static t_node	*tree = NULL;

	if (set)
		tree = set;
	return (&tree);
}

void	free_tree(t_node **tree2)
{
	t_cmd	*cmd;
	t_node	*tree;

	if (tree2 == NULL)
		return ;
	tree = *tree2;
	if (tree == NULL)
		return ;
	free_tree(&(tree->left));
	free_tree(&(tree->right));
	if (tree->type == TN_CMD)
	{
		cmd = (t_cmd*)tree->data;
		ft_freecmd(&cmd);
	}
}

int		parse_cmd(t_list *tokens, char ***envp)
{
	int			ret;
	t_arg_parse	arg;
	int			ret_status;

	ft_bzero(&arg, sizeof(t_arg_parse));
	arg.tokens = tokens;
	arg.envp = envp;
	ret = rule_paradigm(&arg);
	ft_get_tree(arg.tree);
	free_tokens(&tokens);
	if (ret == 0)
		return (ret);
	ft_restore_default(ft_init_term());
	ret_status = ft_resolve_tree(arg.tree);
	ft_last_cmd_return_value(ret_status);
	free_tree(&(arg.tree));
	arg.tree = NULL;
	return (ret);
}
