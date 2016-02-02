/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 16:05:17 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 16:44:37 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "libft.h"

static char		*ft_gen_path_from_list(t_list *list, char *path)
{
	int			i;
	char		*tmp;

	i = 0;
	if (!list)
		path[0] = '/';
	while (list)
	{
		path[i] = '/';
		i++;
		tmp = (char *)ft_listpoplast(&list);
		ft_strcat(&path[i], tmp);
		free(tmp);
		i = ft_strlen(path);
	}
	return (path);
}

void			ft_path_canonize(char **path)
{
	int			i;
	char		*new;
	char		**tab;
	t_list		*list;

	new = ft_strnew(ft_strlen(*path));
	tab = ft_strsplit(*path, '/');
	list = NULL;
	i = 0;
	while (tab[i])
	{
		if (!ft_strequ(tab[i], "."))
		{
			if (ft_strequ(tab[i], ".."))
			{
				if (list)
					free(ft_listpop(&list));
			}
			else if (!ft_strequ(tab[i], ""))
				ft_listpushfront(&list, ft_strdup(tab[i]));
		}
		i++;
	}
	ft_strtabfree(&tab);
	*path = ft_gen_path_from_list(list, new);
}
