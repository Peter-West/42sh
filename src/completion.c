/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 20:27:53 by ppellegr          #+#    #+#             */
/*   Updated: 2014/02/27 20:27:54 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "libft.h"
#include "lexer.h"
#include "completion.h"
#include "builtin.h"

char		*ft_comp_filler(t_check_comp *b, char *res, t_list *list,
							t_comp_var *a)
{
	b->tmp0 = list;
	while (b->tmp0 != NULL)
	{
		b->tmp_c = (t_compl*)b->tmp0->data;
		if (b->c == -1 && b->tmp_c->name[a->len + b->i] != '\0')
		{
			b->check = b->tmp_c->name[a->len + b->i];
			b->c++;
		}
		if (b->check == b->tmp_c->name[a->len + b->i])
		{
			b->c++;
			if (b->c == a->count && res != NULL)
			{
				res = ft_add_letter(b, res, list, a);
				continue ;
			}
		}
		b->tmp0 = b->tmp0->next;
	}
	return (res);
}

char		*ft_check_comp(t_list *list, t_list *tokens, t_comp_var *a)
{
	t_check_comp		*b;
	char				*res;

	b = (t_check_comp*)malloc(sizeof(t_check_comp));
	b->c = -1;
	b->i = 0;
	b->check = '\0';
	res = ft_strdup(VALUE);
	if (list != NULL)
		res = ft_comp_filler(b, res, list, a);
	if (b)
		free(b);
	return (res);
}

int			ft_check_binary(t_list *tokens)
{
	t_list				*tmp;

	tmp = tokens;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (ft_strncmp("./", VALUETMP, 2) == 0)
		return (1);
	else
		return (0);
}

void		ft_dir_completion(t_cmd_line *line, t_comp_var *a, t_list *list,
								t_list *tokens)
{
	while (tokens->next != NULL)
		tokens = tokens->next;
	if (a->binary == 1)
		VALUE = &VALUE[2];
	else if (ft_strchr(VALUE, '/'))
	{
		a->path = ft_catpath(a->path, VALUE);
		a->path = ft_slash_cut(tokens, a);
	}
	a->dirp = opendir(a->path);
	a->len = ft_strlen(VALUE);
	a->len_line = ft_strlen(line->str);
	a->count = ft_completion_count(tokens, a);
	if (a->dirp)
	{
		list = ft_list_feeder(line, a, list, tokens);
	}
	if (a->count > 1)
		ft_multiple_choices_printing(line, a, list, tokens);
}

void		ft_completion(t_cmd_line *line)
{
	t_comp_var			*a;
	t_list				*list;
	t_list				*tokens;

	if (line->str[0] == '\0')
		return ;
	a = (t_comp_var*)malloc(sizeof(t_comp_var));
	list = NULL;
	tokens = ft_tokenize(line->str);
	a->check_toks = ft_check_token(tokens, a);
	a->path = ft_strdup(".");
	if (line->str != NULL && line->str[0] != '\0' && tokens)
	{
		if (a->check_toks == 2)
			ft_cmd_completion(a, tokens, line);
		else if (a->check_toks == 1)
			ft_dir_completion(line, a, list, tokens);
		if (a != NULL)
			free(a);
		if (tokens)
			free(tokens);
	}
}
