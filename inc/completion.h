/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppellegr <ppellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 17:30:30 by ppellegr          #+#    #+#             */
/*   Updated: 2014/03/14 17:30:33 by ppellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H
# define VALUE ((t_token*)(tokens->data))->value
# define VALUETMP ((t_token*)(tmp->data))->value
# define TYPE ((t_token*)(tmp->data))->type
# include "ft_term.h"
# include "sh42.h"
# include <dirent.h>

typedef struct			s_compl
{
	char				*name;
	int					len;
	int					status;
}						t_compl;

typedef struct			s_comp_var
{
	DIR					*dirp;
	struct dirent		*dp;
	char				*path;
	int					count;
	int					len;
	int					len_line;
	int					check_toks;
	int					binary;
}						t_comp_var;

typedef struct			s_check_comp
{
	char				*res_tmp;
	t_list				*tmp0;
	t_compl				*tmp_c;
	char				check;
	int					i;
	int					c;
}						t_check_comp;

void					ft_completion(t_cmd_line *line);
void					ft_completion_print(t_list *list);
void					ft_cmd_completion(t_comp_var *a, t_list *tokens,
							t_cmd_line *line);
char					*ft_check_comp(t_list *list, t_list *tokens,
							t_comp_var *a);
int						ft_check_token(t_list *tokens, t_comp_var *a);
int						ft_completion_count(t_list *tokens, t_comp_var *a);
void					ft_multiple_choices_printing(t_cmd_line *line,
							t_comp_var *a, t_list *list, t_list *tokens);
t_list					*ft_list_feeder(t_cmd_line *line, t_comp_var *a,
							t_list *list, t_list *tokens);
int						ft_check_binary(t_list *tokens);
char					*ft_slash_cut(t_list *tokens, t_comp_var *a);
char					*ft_realloc(char *path, char *str);
char					*ft_add_letter(t_check_comp *b, char *res,
							t_list *list, t_comp_var *a);

#endif
