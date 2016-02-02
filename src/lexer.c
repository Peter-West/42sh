/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:32:53 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/21 18:49:45 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "lexer.h"
#include "libft.h"
#include "list.h"
#include "error.h"

t_list		*ft_tokenize(char *str)
{
	t_list	*tokens;
	t_token	*token;
	int		pos;

	pos = 0;
	tokens = NULL;
	while (str[pos])
	{
		while (str[pos] && ft_strchr(DELIMITER, str[pos]))
			++pos;
		if ((token = ft_get_token(str, &pos)))
			ft_listpushback(&tokens, token);
		else
			break ;
	}
	return (tokens);
}

t_token		*ft_get_token(char *str, int *pos)
{
	if (ft_strchr(OPERATOR, str[*pos]))
		return (ft_get_operator(str, pos));
	else
		return (ft_get_file(str, pos));
}

int			ft_get_file_token_len(char *str)
{
	int		len;
	char	quote;
	char	*tmp;

	quote = 0;
	len = 0;
	while (str[len])
	{
		if (quote && (tmp = ft_strchr(QUOTE, str[len])) && quote == *tmp)
		{
			if (ft_strchr(DELIMITER, str[len + 1]) || !str[len + 1]
					|| ft_strchr(OPERATOR, str[len + 1]))
			{
				++len;
				break ;
			}
		}
		else if (!quote && ft_strchr(QUOTE, str[len]))
			quote = *ft_strchr(QUOTE, str[len]);
		else if (!quote && (ft_strchr(DELIMITER, str[len])
					|| ft_strchr(OPERATOR, str[len])))
			break ;
		++len;
	}
	return (len);
}

t_token		*ft_get_file(char *str, int *pos)
{
	t_token	*token;
	char	*value;
	int		len;

	if ((!(len = ft_get_file_token_len(&str[*pos]))))
		return (NULL);
	if ((!(token = (t_token*)malloc(sizeof(t_token)))))
		ft_error(ERR_MALLOC);
	token->type = T_FILE;
	if ((!(value = ft_strsub(str, *pos, len))))
		ft_error(ERR_MALLOC);
	if ((!(value = ft_rm_quote(value))))
		ft_error(ERR_MALLOC);
	if ((!(token->value = ft_rm_escape(value))))
		ft_error(ERR_MALLOC);
	*pos += len;
	free(value);
	return (token);
}

t_token		*ft_get_operator(char *str, int *pos)
{
	t_token	*token;
	int		i;
	int		i2;

	i = *pos;
	if ((!(token = (t_token*)malloc(sizeof(t_token)))))
		ft_error(ERR_MALLOC);
	token->type = ft_get_operator_token_type(str, pos);
	if (token->type == T_REDIR_RIGHT_2)
		++(*pos);
	else if (token->type == T_AND || token->type == T_OR)
		++(*pos);
	++(*pos);
	i2 = *pos - i;
	token->value = ft_strsub(str, i, i2);
	return (token);
}
