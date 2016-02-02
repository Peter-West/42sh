/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 16:26:46 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 18:09:09 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_get_next_line.h"
#include "libft.h"

static int				ft_have_line(char *str, int *len)
{
	int				pos;

	if (str)
	{
		pos = 0;
		while (pos < *len)
		{
			if (str[pos] == '\n')
				return (pos);
			pos++;
		}
	}
	return (-1);
}

static int				ft_delline(char **str, int *len, int pos)
{
	char			*tmp;

	if (pos >= *len)
	{
		free(*str);
		*str = NULL;
		*len = 0;
		return (1);
	}
	tmp = *str;
	if (!((*str = ft_strsub(*str, pos + 1, *len - (pos + 1)))))
		return (0);
	free(tmp);
	*len = *len - (pos + 1);
	return (1);
}

static int				ft_getfdid(int fd, int tabfdid[MAX_FD_NBR])
{
	int		i;

	if (fd == 0)
		return (0);
	i = 1;
	while (i < MAX_FD_NBR)
	{
		if (tabfdid[i] == fd)
			return (i);
		i++;
	}
	i = 1;
	while (i < MAX_FD_NBR)
	{
		if (tabfdid[i] == 0)
		{
			tabfdid[i] = fd;
			return (i);
		}
		i++;
	}
	return (-1);
}

static int				ft_read(char **str, int const fd, int *len)
{
	int				ret;
	int				pos;
	char			buf[BUFF_SIZE];
	char			*tmp;

	ret = 1;
	while (((pos = ft_have_line(*str, len)) == -1) && ret)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (ret);
		if (ret == 0)
			break ;
		tmp = *str;
		if (!((*str = (char *)ft_memcat(*str, buf, *len, ret))))
			return (-1);
		*len += ret;
		if (tmp)
			free(tmp);
	}
	if (ret == 0 && pos == -1 && *len > 0)
		return (*len);
	else if (ret == 0 && pos == -1)
		return (-2);
	return (pos);
}

int						ft_get_next_line(int const fd, char **line)
{
	static char		*str[MAX_FD_NBR] = {0};
	static int		len[MAX_FD_NBR] = {0};
	static int		tabidfd[MAX_FD_NBR] = {0};
	int				pos;
	int				fdid;

	if ((fdid = ft_getfdid(fd, tabidfd)) == -1)
		return (-1);
	pos = ft_read(&str[fdid], fd, &len[fdid]);
	if (pos == -1)
		return (-1);
	else if (pos == -2)
		return (0);
	if (!((*line = ft_strsub(str[fdid], 0, pos))))
		return (-1);
	if (!ft_delline(&str[fdid], &len[fdid], pos))
		return (-1);
	return (1);
}
