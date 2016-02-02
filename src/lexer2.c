/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:32:53 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 16:46:58 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer.h"
#include "libft.h"

char			*ft_rm_escape(char *str)
{
	char	*ret;
	char	*cpy;

	if ((!(ret = ft_strnew(ft_strlen(str)))))
		return (NULL);
	cpy = ret;
	while (*str)
	{
		if (!ft_strchr(ESCAPE, *str))
		{
			*ret = *str;
			++ret;
		}
		else if (ft_strchr(ESCAPE, *str) && ft_strchr(ESCAPE, str[1]))
		{
			*ret = *str;
			++ret;
			++str;
		}
		++str;
	}
	return (cpy);
}

void			ft_free_token(t_token **token)
{
	free((*token)->value);
	free(*token);
	*token = NULL;
}

char			*ft_rm_quote(char *str)
{
	char	*ret;
	char	q;
	char	*cpy;
	char	*ret_cpy;

	q = 0;
	cpy = str;
	if ((!(ret = ft_strnew(ft_strlen(str)))))
		return (NULL);
	ret_cpy = ret;
	while (*str)
	{
		if (!q && ft_strchr(QUOTE, *str) && (str == cpy || *(str - 1) != '\\'))
			q = *str;
		else if (q && q == *str && *(str - 1) != '\\')
			q = 0;
		else
		{
			*ret = *str;
			++ret;
		}
		++str;
	}
	free(cpy);
	return (ret_cpy);
}

void			free_tokens(t_list **ptr_tokens)
{
	t_list	*tokens;
	t_list	*prev_tok;
	t_token	*tok;

	tokens = *ptr_tokens;
	while (tokens != NULL)
	{
		tok = (t_token*)tokens->data;
		ft_free_token(&tok);
		prev_tok = tokens;
		tokens = tokens->next;
		free(prev_tok);
	}
}

t_token_type	ft_get_operator_token_type(char *str, int *pos)
{
	if (str[*pos] == '<')
		return (T_REDIR_LEFT);
	else if (str[*pos] == '>' && str[*pos + 1] == '>')
		return (T_REDIR_RIGHT_2);
	else if (str[*pos] == '|' && str[*pos + 1] == '|')
		return (T_OR);
	else if (str[*pos] == '&' && str[*pos + 1] == '&')
		return (T_AND);
	else if (str[*pos] == '>')
		return (T_REDIR_RIGHT_1);
	else if (str[*pos] == ';')
		return (T_SEMICOLON);
	else if (str[*pos] == '|')
		return (T_PIPE);
	return (0);
}
