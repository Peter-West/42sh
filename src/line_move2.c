/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_move2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 23:27:14 by rfrey             #+#    #+#             */
/*   Updated: 2014/02/21 14:54:18 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_term.h"

void		ft_next_word(t_cmd_line *line)
{
	int		len;

	len = ft_strlen(line->str);
	while (line->pos < len && !ft_strchr(" ", line->str[line->pos]))
		ft_key_right(line);
	while (line->pos < len && ft_strchr(" ", line->str[line->pos]))
		ft_key_right(line);
}

void		ft_prev_word(t_cmd_line *line)
{
	while (line->pos > 0 && ft_strchr(" ", line->str[line->pos - 1]))
		ft_key_left(line);
	while (line->pos > 0 && !ft_strchr(" ", line->str[line->pos - 1]))
		ft_key_left(line);
}
