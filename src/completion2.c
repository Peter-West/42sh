/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 17:54:44 by ppellegr          #+#    #+#             */
/*   Updated: 2014/03/19 17:54:45 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "libft.h"
#include "lexer.h"
#include "completion.h"
#include "builtin.h"

char		**ft_cut_path_compl(char *path)
{
	char	**paths;

	paths = ft_strsplit(path, ':');
	return (paths);
}

int			ft_completion_count_cmd(t_list *tokens, t_comp_var *a,
									char **paths)
{
	DIR					*dirp;
	struct dirent		*dp;
	int					i;
	int					j;

	i = 0;
	j = 0;
	if (VALUE != NULL)
	{
		while (paths[j] != NULL)
		{
			dirp = opendir(paths[j]);
			while (dirp && (dp = readdir(dirp)) != NULL)
			{
				if ((ft_strncmp(dp->d_name, VALUE, a->len)) == 0)
					i++;
			}
			j++;
			if (dirp)
				closedir(dirp);
		}
	}
	return (i);
}

void		ft_cmd_completion(t_comp_var *a, t_list *tokens, t_cmd_line *line)
{
	t_list				*list;
	int					i;
	char				**paths;

	list = NULL;
	i = 0;
	paths = ft_cut_path_compl(ft_getenv(line->envp, "PATH"));
	while (paths[i] != NULL)
	{
		a->dirp = opendir(paths[i++]);
		while (tokens->next != NULL)
			tokens = tokens->next;
		a->len = ft_strlen(VALUE);
		a->len_line = ft_strlen(line->str);
		a->count = ft_completion_count_cmd(tokens, a, paths);
		if (a->dirp)
			list = ft_list_feeder(line, a, list, tokens);
	}
	if (a->count > 1)
		ft_multiple_choices_printing(line, a, list, tokens);
}

void		ft_completion_print(t_list *list)
{
	t_list			*tmp;
	t_compl			*tmp_c;

	tmp = list;
	ft_printf("\n");
	while (tmp != NULL)
	{
		tmp_c = (t_compl*)tmp->data;
		ft_printf("%s", tmp_c->name);
		if (tmp->next != NULL)
			ft_printf("\t");
		tmp_c = NULL;
		tmp = tmp->next;
	}
	if (list != NULL)
		free(list);
}
