/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 18:05:44 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 16:45:13 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_term.h"

int		ft_check_quote(t_cmd_line *line)
{
	int		i;

	i = 0;
	while (line->str[i])
	{
		if (line->str[i] == '\'' && (!i || line->str[i - 1] != '\\'))
		{
			++i;
			while (line->str[i] && line->str[i] != '\'')
				++i;
			if (!line->str[i])
				return (ft_miss_quote(line, '\''));
		}
		else if (line->str[i] == '"' && (!i || line->str[i - 1] != '\\'))
		{
			++i;
			while (line->str[i] && line->str[i] != '"')
				++i;
			if (!line->str[i])
				return (ft_miss_quote(line, '"'));
		}
		++i;
	}
	return (0);
}

int		ft_miss_quote(t_cmd_line *line, char quote_type)
{
	t_cmd_line	*tmp;
	char		key[4];
	t_historic	*historic;
	char		*old_line;

	ft_bzero(key, 4);
	if (quote_type == '\'')
		ft_printf("quote> ");
	else if (quote_type == '"')
		ft_printf("dquote> ");
	tmp = ft_init_cmd_line(line->envp);
	historic = ft_init_historic();
	while (ft_handle_key(key, tmp, historic))
	{
		ft_bzero(key, 4);
		read(0, key, 4);
	}
	ft_putchar('\n');
	old_line = line->str;
	line->str = ft_strjoin(line->str, tmp->str);
	free(old_line);
	ft_free_cmd_line(&tmp);
	ft_check_quote(line);
	return (0);
}
