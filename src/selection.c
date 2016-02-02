/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 18:13:37 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 16:49:36 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "key.h"
#include "ft_term.h"

void		ft_sel_mode_key(char key[4], t_cmd_line *line)
{
	if (KEY_LEFT)
		ft_sel_left(line);
	if (KEY_RIGHT)
		ft_sel_right(line);
	else if (KEY_CO)
		ft_copy(line);
	else if (KEY_CU)
		ft_cut(line);
	else if (KEY_HOME)
		ft_sel_home(line);
	else if (KEY_END)
		ft_sel_end(line);
	else if (KEY_ESC)
		ft_sel_cancel(line);
}

void		ft_sel_home(t_cmd_line *line)
{
	while (line->pos)
		ft_sel_left(line);
}

void		ft_sel_end(t_cmd_line *line)
{
	int		len;

	len = ft_strlen(line->str);
	while (line->pos < len - 1)
		ft_sel_right(line);
}

void		ft_sel_right(t_cmd_line *line)
{
	if (line->pos == (int)ft_strlen(line->str) - 1)
		return ;
	if (!(line->pos + 1 > line->sel_end))
	{
		++line->sel_start;
		ft_putchar(line->str[line->pos]);
		++line->pos;
	}
	else
	{
		++line->sel_end;
		++line->pos;
		tputs(tgetstr("nd", NULL), 1, ft_put_term_char);
		tputs(tgetstr("mr", NULL), 1, ft_put_term_char);
		ft_putchar(line->str[line->pos]);
		tputs(tgetstr("me", NULL), 1, ft_put_term_char);
		tputs(tgetstr("le", NULL), 1, ft_put_term_char);
	}
}

void		ft_sel_left(t_cmd_line *line)
{
	if (line->pos == 0)
		return ;
	if (!(line->pos - 1 < line->sel_start))
	{
		ft_putchar(line->str[line->pos]);
		tputs(tgetstr("le", NULL), 1, ft_put_term_char);
		tputs(tgetstr("le", NULL), 1, ft_put_term_char);
		--line->sel_end;
		--line->pos;
		return ;
	}
	else
	{
		--line->sel_start;
		--line->pos;
		tputs(tgetstr("le", NULL), 1, ft_put_term_char);
		tputs(tgetstr("mr", NULL), 1, ft_put_term_char);
		ft_putchar(line->str[line->pos]);
		tputs(tgetstr("me", NULL), 1, ft_put_term_char);
		tputs(tgetstr("le", NULL), 1, ft_put_term_char);
	}
}
