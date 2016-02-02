/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 20:33:22 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/21 17:35:12 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_term.h"

void	ft_key_end(t_cmd_line *line)
{
	int	len;

	len = ft_strlen(line->str);
	while (line->pos < len)
	{
		tputs(tgetstr("nd", NULL), 1, ft_put_term_char);
		++(line->pos);
	}
}

void	ft_key_home(t_cmd_line *line)
{
	while (line->pos > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_put_term_char);
		--(line->pos);
	}
	line->pos = 0;
}

void	ft_key_left(t_cmd_line *line)
{
	--(line->pos);
	tputs(tgetstr("le", NULL), 1, ft_put_term_char);
}

void	ft_key_right(t_cmd_line *line)
{
	++(line->pos);
	tputs(tgetstr("nd", NULL), 1, ft_put_term_char);
}
