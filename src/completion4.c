/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:15:00 by ppellegr          #+#    #+#             */
/*   Updated: 2014/03/27 19:15:01 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "libft.h"
#include "lexer.h"
#include "completion.h"
#include "builtin.h"

char			*ft_add_letter(t_check_comp *b, char *res, t_list *list,
								t_comp_var *a)
{
	b->res_tmp = ft_strdup(res);
	res = NULL;
	free(res);
	res = (char*)malloc(sizeof(char) * (a->len + b->i + 2));
	res[0] = '\0';
	ft_strcpy(res, b->res_tmp);
	if (b->res_tmp)
		free(b->res_tmp);
	res[a->len + b->i] = b->check;
	res[a->len + b->i + 1] = '\0';
	b->res_tmp = res;
	b->c = -1;
	b->i++;
	b->tmp0 = list;
	return (res);
}
