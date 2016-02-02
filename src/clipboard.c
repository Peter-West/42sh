/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 21:04:25 by rfrey             #+#    #+#             */
/*   Updated: 2014/02/21 14:52:33 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_term.h"

void		ft_init_clipboard(t_cmd_line *line)
{
	int		len;

	len = ft_strlen(line->str);
	if (!len)
		return ;
	if (line->pos == len)
		ft_key_left(line);
	line->sel_mode = 1;
	line->sel_start = line->pos;
	line->sel_end = line->pos;
	tputs(tgetstr("mr", NULL), 1, ft_put_term_char);
	ft_putchar(line->str[line->pos]);
	tputs(tgetstr("me", NULL), 1, ft_put_term_char);
	tputs(tgetstr("le", NULL), 1, ft_put_term_char);
}

void		ft_copy(t_cmd_line *line)
{
	int		sel_len;

	line->sel_mode = 0;
	sel_len = line->sel_end - line->sel_start + 1;
	ft_clipboard(ft_strsub(line->str, line->sel_start, sel_len));
	ft_refresh_line(line);
}

void		ft_cut(t_cmd_line *line)
{
	int		sel_len;

	line->sel_mode = 0;
	sel_len = line->sel_end - line->sel_start + 1;
	ft_clipboard(ft_strsub(line->str, line->sel_start, sel_len));
	ft_key_home(line);
	while (line->pos < line->sel_start)
		ft_key_right(line);
	while (sel_len--)
		ft_key_del(line);
	ft_refresh_line(line);
}

char		*ft_clipboard(char *str)
{
	static char	*clipboard = NULL;

	if (str)
	{
		if (clipboard)
			free(clipboard);
		clipboard = str;
	}
	return (clipboard);
}

void		ft_paste(t_cmd_line *line)
{
	char	*str;

	if ((str = ft_clipboard(NULL)))
	{
		while (*str)
		{
			ft_add_char(*str, line);
			++str;
		}
	}
}
