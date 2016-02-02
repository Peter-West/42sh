/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 20:31:48 by rfrey             #+#    #+#             */
/*   Updated: 2014/02/21 14:51:21 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_term.h"

void		ft_add_char(char c, t_cmd_line *line)
{
	int		len;

	tputs(tgetstr("im", NULL), 1, ft_put_term_char);
	ft_putchar(c);
	tputs(tgetstr("ei", NULL), 1, ft_put_term_char);
	len = ft_strlen(line->str);
	if (len >= line->len)
		ft_extend_cmd_line(line);
	while (len > line->pos)
	{
		line->str[len] = line->str[len - 1];
		--len;
	}
	line->str[len] = c;
	++(line->pos);
}

void		ft_key_del(t_cmd_line *line)
{
	int		len;
	int		i;

	len = ft_strlen(line->str);
	tputs(tgetstr("dm", NULL), 1, ft_put_term_char);
	tputs(tgetstr("dc", NULL), 1, ft_put_term_char);
	tputs(tgetstr("ed", NULL), 1, ft_put_term_char);
	i = line->pos;
	line->str[len] = '\0';
	while (line->str[i])
	{
		line->str[i] = line->str[i + 1];
		++i;
	}
}

void		ft_key_backdel(t_cmd_line *line)
{
	if (line->pos < 1)
		return ;
	tputs(tgetstr("le", NULL), 1, ft_put_term_char);
	--line->pos;
	ft_key_del(line);
}

void		ft_refresh_line(t_cmd_line *line)
{
	int		pos;
	int		len;

	len = ft_strlen(line->str);
	pos = line->pos;
	ft_delete_line(line);
	ft_putstr(line->str);
	while (pos < len)
	{
		tputs(tgetstr("le", NULL), 1, ft_put_term_char);
		--len;
	}
	line->pos = pos;
}
