/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 02:04:08 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/21 22:17:35 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "libft.h"
#include "error.h"
#include "ft_term.h"

t_historic		*ft_init_historic(void)
{
	t_historic	*historic;

	if ((!(historic = (t_historic*)malloc(sizeof(t_historic)))))
		ft_error(ERR_MALLOC);
	historic->list = NULL;
	historic->pos = 0;
	return (historic);
}

void			ft_key_up(t_cmd_line *line, t_historic *historic)
{
	t_list	*list;

	if (!historic->list || historic->pos + 1 > ft_listcnt(historic->list))
		return ;
	ft_delete_line(line);
	if ((list = ft_listgetn(historic->list, historic->pos + 1)))
	{
		++(historic->pos);
		ft_putstr((char*)list->data);
		ft_strclr(line->str);
		ft_strcpy(line->str, (char*)list->data);
		line->pos += ft_strlen((char*)list->data);
	}
}

void			ft_key_down(t_cmd_line *line, t_historic *historic)
{
	t_list	*list;
	char	*tmp;

	if (!historic->list)
		return ;
	ft_delete_line(line);
	if ((list = ft_listgetn(historic->list, historic->pos - 1)))
	{
		--(historic->pos);
		tmp = (char*)list->data;
		ft_putstr(tmp);
		ft_strclr(line->str);
		while (line->len < (int)ft_strlen(tmp) + 1)
			ft_extend_cmd_line(line);
		ft_strcpy(line->str, tmp);
		line->pos += ft_strlen(tmp);
	}
	else if (historic->pos == 1)
	{
		historic->pos = 0;
		ft_strclr(line->str);
	}
}

void			ft_delete_line(t_cmd_line *line)
{
	int		len;

	len = ft_strlen(line->str);
	ft_key_home(line);
	tputs(tgetstr("dm", NULL), 1, ft_put_term_char);
	while (len--)
		tputs(tgetstr("dc", NULL), 1, ft_put_term_char);
	tputs(tgetstr("ed", NULL), 1, ft_put_term_char);
}
