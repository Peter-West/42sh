/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 17:58:49 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 16:49:19 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "builtin.h"
#include "key.h"
#include "libft.h"
#include "ft_term.h"

int			ft_put_term_char(int c)
{
	ft_putchar_fd(c, 1);
	return (c);
}

char		*ft_get_cmd(char **envp)
{
	t_cmd_line			*line;
	char				*cpy;
	char				key[4];
	static t_historic	*historic = NULL;

	ft_bzero(key, 4);
	if (!historic)
		historic = ft_init_historic();
	line = ft_init_cmd_line(envp);
	ft_init_term();
	ft_init_signal();
	while (ft_handle_key(key, line, historic))
	{
		ft_bzero(key, 4);
		read(0, key, 4);
	}
	ft_putchar('\n');
	ft_check_quote(line);
	cpy = ft_strdup(line->str);
	if (!ft_strequ(line->str, ""))
		ft_listpushfront(&(historic->list), cpy);
	historic->pos = 0;
	ft_free_cmd_line(&line);
	return (cpy);
}

int			ft_handle_key(char key[4], t_cmd_line *line, t_historic *hist)
{
	if (KEY_RET)
		return (0);
	else if (KEY_TAB)
		ft_completion(line);
	else if (KEY_SHIFT)
		ft_shift(line);
	else if (line->sel_mode)
		ft_sel_mode_key(key, line);
	else
		ft_simple_key(key, line, hist);
	return (1);
}

void		ft_simple_key(char key[4], t_cmd_line *line, t_historic *historic)
{
	if (KEY_PRINTABLE)
		ft_add_char(key[0], line);
	else if (KEY_LEFT && line->pos > 0)
		ft_key_left(line);
	else if (KEY_RIGHT && line->pos < (int)ft_strlen(line->str))
		ft_key_right(line);
	else if (KEY_HOME)
		ft_key_home(line);
	else if (KEY_END)
		ft_key_end(line);
	else if (KEY_UP)
		ft_key_up(line, historic);
	else if (KEY_DOWN)
		ft_key_down(line, historic);
	else if (KEY_DEL)
		ft_key_del(line);
	else if (KEY_BSP)
		ft_key_backdel(line);
	else if (KEY_SEL)
		ft_init_clipboard(line);
	else if (KEY_PA)
		ft_paste(line);
	else if (KEY_CTRLD)
		ft_quit();
}

void		ft_shift(t_cmd_line *line)
{
	char	key[4];

	read(0, key, 4);
	if (KEY_WNEXT)
		ft_next_word(line);
	else if (KEY_WPREV)
		ft_prev_word(line);
}
