/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 22:39:32 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/11 23:06:28 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "libft.h"
#include "ft_term.h"
#include "error.h"

t_cmd_line	*ft_init_cmd_line(char **envp)
{
	t_cmd_line	*line;

	if ((!(line = (t_cmd_line*)malloc(sizeof(t_cmd_line)))))
		ft_error(ERR_MALLOC);
	if ((!(line->str = ft_strnew(CMD_LINE_BUF))))
		ft_error(ERR_MALLOC);
	line->envp = envp;
	line->len = CMD_LINE_BUF;
	line->pos = 0;
	line->sel_mode = 0;
	line->sel_start = 0;
	line->sel_end = 0;
	return (line);
}

void		ft_extend_cmd_line(t_cmd_line *line)
{
	char	*tmp;

	tmp = line->str;
	line->len += CMD_LINE_BUF;
	if ((!(line->str = ft_strnew(line->len))))
		ft_error(ERR_MALLOC);
	ft_strcpy(line->str, tmp);
	free(tmp);
}

void		ft_free_cmd_line(t_cmd_line **line)
{
	free((*line)->str);
	free(*line);
	*line = NULL;
}
