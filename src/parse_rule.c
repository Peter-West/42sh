/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 00:45:53 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/11 22:50:49 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				test_bool(t_arg_parse *arg, int *ret, t_token_type type)
{
	if (is_type(&(arg->tokens), type))
	{
		*ret = rule_pipeline(arg);
		if (*ret)
			generate_boolline(arg, type);
		return (*ret);
	}
	return (0);
}

int				rule_boolline(t_arg_parse *arg)
{
	t_arg_parse	before;
	int			carry_on;
	int			ret;

	set_arg_parse(&before, arg);
	ret = rule_pipeline(arg);
	if (ret)
		generate_boolline(arg, 0);
	carry_on = ret;
	while (carry_on && ret)
		carry_on = test_bool(arg, &ret, T_AND) || test_bool(arg, &ret, T_OR);
	if (!ret)
		restore(arg, &before);
	return (ret);
}

int				rule_pipeline(t_arg_parse *arg)
{
	t_arg_parse	before;
	int			ret;
	int			carry_on;

	set_arg_parse(&before, arg);
	ret = rule_cmd(arg);
	if (ret)
		generate_pipe(arg);
	carry_on = ret;
	while (carry_on)
	{
		if (is_type(&(arg->tokens), T_PIPE))
		{
			ret = rule_cmd(arg);
			carry_on = ret;
			if (ret)
				generate_pipe(arg);
		}
		else
			carry_on = 0;
	}
	if (!ret)
		restore(arg, &before);
	return (ret);
}

int				rule_semi_col(t_arg_parse *arg)
{
	t_arg_parse	before;
	int			ret;
	int			carry_on;

	set_arg_parse(&before, arg);
	ret = rule_boolline(arg);
	if (ret)
		generate_semicol(arg);
	carry_on = ret;
	while (carry_on)
	{
		if (is_type(&(arg->tokens), T_SEMICOLON))
		{
			ret = rule_boolline(arg);
			if (ret)
				generate_semicol(arg);
		}
		else
			carry_on = 0;
	}
	if (!ret)
		restore(arg, &before);
	return (ret);
}

int				rule_paradigm(t_arg_parse *arg)
{
	t_arg_parse	before;
	int			ret;

	set_arg_parse(&before, arg);
	ret = 1;
	while (arg->tokens != NULL && ret)
	{
		ret = rule_semi_col(arg);
		if (!ret)
			ft_putendl_fd("error parsing", 2);
	}
	if (!ret)
		restore(arg, &before);
	return (ret);
}
