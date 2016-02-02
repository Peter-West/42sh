/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 19:14:54 by ppellegr          #+#    #+#             */
/*   Updated: 2014/03/26 19:14:55 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "libft.h"
#include "lexer.h"
#include "completion.h"
#include "builtin.h"

t_list		*ft_list_feeder(t_cmd_line *line, t_comp_var *a, t_list *list,
							t_list *tokens)
{
	t_compl				*comp;

	comp = NULL;
	while ((a->dp = readdir(a->dirp)) != NULL && VALUE[0] != '\0')
	{
		if ((ft_strncmp(a->dp->d_name, VALUE, a->len)) == 0)
		{
			if (a->count == 1)
			{
				ft_putstr_fd(&a->dp->d_name[a->len], 1);
				line->str = ft_strsub(line->str, 0, a->len_line - a->len);
				line->str = ft_strjoin(line->str, a->dp->d_name);
				line->pos = ft_strlen(line->str);
			}
			else if (a->count > 1)
			{
				comp = (t_compl*)malloc(sizeof(t_compl));
				comp->name = ft_strdup(a->dp->d_name);
				comp->len = ft_strlen(a->dp->d_name);
				ft_listpushback(&list, comp);
			}
		}
	}
	closedir(a->dirp);
	return (list);
}

int			ft_check_token(t_list *tokens, t_comp_var *a)
{
	t_list				*tmp;
	int					count;
	int					i;

	i = 0;
	a->binary = 0;
	tmp = tokens;
	count = ft_listcnt(tmp);
	while (i < (count - 2))
	{
		tmp = tmp->next;
		i++;
	}
	if (ft_check_binary(tokens) == 1)
	{
		a->binary = 1;
		return (1);
	}
	if (TYPE == T_SEMICOLON || TYPE == T_PIPE || TYPE == T_AND ||
		TYPE == T_OR || count < 2)
		return (2);
	if ((TYPE == T_FILE || TYPE == T_REDIR_LEFT ||
		TYPE == T_REDIR_RIGHT_1 || TYPE == T_REDIR_RIGHT_2) && count > 1)
		return (1);
	return (0);
}

int			ft_completion_count(t_list *tokens, t_comp_var *a)
{
	DIR					*dirp;
	struct dirent		*dp;
	int					i;

	i = 0;
	if (VALUE != NULL)
	{
		dirp = opendir(a->path);
		if (dirp)
		{
			while ((dp = readdir(dirp)) != NULL)
			{
				if ((ft_strncmp(dp->d_name, VALUE, a->len)) == 0)
					i++;
			}
			closedir(dirp);
		}
	}
	return (i);
}

void		ft_multiple_choices_printing(t_cmd_line *line, t_comp_var *a,
											t_list *list, t_list *tokens)
{
	char		*tmp;
	char		*tmp2;
	int			i;

	i = 0;
	tmp = ft_strdup(line->str);
	line->str = NULL;
	free(line->str);
	line->str = ft_strsub(tmp, 0, a->len_line - a->len);
	free(tmp);
	tmp2 = ft_check_comp(list, tokens, a);
	line->str = ft_strjoin(line->str, tmp2);
	free(tmp2);
	if ((int)ft_strlen(line->str) > a->len_line)
	{
		ft_putstr_fd(&line->str[a->len_line], 1);
		line->pos = ft_strlen(line->str);
		line->len = ft_strlen(line->str);
	}
	ft_completion_print(list);
	ft_printf("\n");
	ft_prompt(line->envp);
	ft_printf("%s", line->str);
}

char		*ft_slash_cut(t_list *tokens, t_comp_var *a)
{
	int					i;
	int					len;
	char				*tmp_value;

	i = (ft_strlen(VALUE) - 1);
	len = i;
	while (i >= 0)
	{
		if (VALUE[i] == '/')
		{
			a->path = ft_strsub(VALUE, 0, i);
			tmp_value = VALUE;
			VALUE = ft_strsub(VALUE, i + 1, len - i);
			free(tmp_value);
			break ;
		}
		i--;
	}
	return (a->path);
}
