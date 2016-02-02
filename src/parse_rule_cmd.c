/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rule_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 16:45:02 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/21 19:08:45 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				rule_redir_in(t_arg_parse *arg)
{
	t_arg_parse	before;
	int			ret;

	set_arg_parse(&before, arg);
	ret = is_type(&(arg->tokens), T_REDIR_LEFT)
		&& is_type(&(arg->tokens), T_FILE);
	if (!ret)
		restore(arg, &before);
	return (ret);
}

int				rule_redir_out(t_arg_parse *arg)
{
	t_arg_parse	before;
	int			ret;

	set_arg_parse(&before, arg);
	ret = (is_type(&(arg->tokens), T_REDIR_RIGHT_1)
		|| is_type(&(arg->tokens), T_REDIR_RIGHT_2))
		&& is_type(&(arg->tokens), T_FILE);
	if (!ret)
		restore(arg, &before);
	return (ret);
}

int				rule_cmd(t_arg_parse *arg)
{
	t_arg_parse	before;
	int			ret;
	int			carry_on;

	set_arg_parse(&before, arg);
	carry_on = 1;
	ret = 0;
	while (carry_on)
	{
		ret = ret || (get_type(arg->tokens) == T_FILE);
		carry_on = rule_redir_in(arg) || rule_redir_out(arg)
			|| is_type(&(arg->tokens), T_FILE);
	}
	if (!ret)
		restore(arg, &before);
	else
		arg->cmd = ft_build_cmd(arg, before.tokens);
	return (ret);
}
