/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 18:28:06 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/11 23:03:58 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "lexer.h"
#include "libft.h"
#include "list.h"
#include "parse.h"
#include "error.h"

void			ft_push_redir(t_cmd *cmd, t_redir *redir)
{
	int		i;
	int		cnt;
	t_redir	**old;

	old = cmd->redir;
	cnt = 0;
	i = 0;
	while (cmd->redir[cnt])
		++cnt;
	if ((!(cmd->redir = (t_redir**)malloc(sizeof(t_redir*) * (cnt + 2)))))
		ft_error(ERR_MALLOC);
	while (i < cnt)
	{
		cmd->redir[i] = old[i];
		++i;
	}
	cmd->redir[i] = redir;
	cmd->redir[i + 1] = NULL;
	free(old);
}

static void		ft_add_redir(t_list **tok, t_cmd *cmd, t_token_type tt)
{
	t_token			*tmp;
	t_redir			*redir;
	t_redir_type	type;

	*tok = (*tok)->next;
	tmp = (t_token*)(*tok)->data;
	if (tt == T_REDIR_LEFT)
		type = RED_LEFT_1;
	else if (tt == T_REDIR_RIGHT_1)
		type = RED_RIGHT_1;
	if (tt == T_REDIR_RIGHT_2)
		type = RED_RIGHT_2;
	redir = ft_init_redir(tmp->value, type);
	ft_push_redir(cmd, redir);
}

t_cmd			*ft_build_cmd(t_arg_parse *arg, t_list *start)
{
	t_cmd		*cmd;
	t_token		*tok;

	cmd = ft_create_cmd(arg->envp);
	while (start != arg->tokens)
	{
		tok = (t_token*)start->data;
		if (tok->type == T_FILE)
			ft_strtabadd(&(cmd->args), ft_strdup(tok->value));
		else if (tok->type == T_REDIR_LEFT
					|| tok->type == T_REDIR_RIGHT_1
					|| tok->type == T_REDIR_RIGHT_2)
			ft_add_redir(&start, cmd, tok->type);
		start = start->next;
	}
	cmd->cmd = cmd->args[0];
	return (cmd);
}
