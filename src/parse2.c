/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 00:45:46 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/26 16:47:05 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void			set_arg_parse(t_arg_parse *dst, t_arg_parse *src)
{
	dst->tokens = src->tokens;
}

void			restore(t_arg_parse *dst, t_arg_parse *svg)
{
	dst->tokens = svg->tokens;
}

t_token_type	get_type(t_list *lst)
{
	t_token	*t;

	if (lst == NULL || lst->data == NULL)
		return (T_NULL);
	t = (t_token*)lst->data;
	return (t->type);
}

int				is_type(t_list **tokens, t_token_type to_compare)
{
	if (*tokens != NULL && get_type(*tokens) == to_compare)
	{
		*tokens = (*tokens)->next;
		return (1);
	}
	return (0);
}
