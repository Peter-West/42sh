/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 23:14:40 by rfrey             #+#    #+#             */
/*   Updated: 2014/02/21 14:54:01 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

void		ft_sel_cancel(t_cmd_line *line)
{
	line->sel_mode = 0;
	ft_refresh_line(line);
}
