/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:33:06 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 17:55:19 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# define DELIMITER " \t"
# define OPERATOR "<>;|&"
# define ESCAPE "\\"
# define QUOTE "'\""
# include "list.h"

typedef enum		e_token_type
{
	T_EOS,
	T_SEMICOLON,
	T_REDIR_LEFT,
	T_REDIR_RIGHT_1,
	T_REDIR_RIGHT_2,
	T_PIPE,
	T_AND,
	T_OR,
	T_NULL,
	T_FILE
}					t_token_type;

typedef struct		s_token
{
	t_token_type	type;
	char			*value;
}					t_token;

t_list				*ft_tokenize(char *str);
t_token				*ft_get_token(char *str, int *pos);
int					ft_get_file_token_len(char *str);
t_token				*ft_get_file(char *str, int *pos);
t_token				*ft_get_operator(char *str, int *pos);
char				*ft_rm_escape(char *str);
void				ft_free_token(t_token **token);
char				*ft_rm_quote(char *str);
t_token_type		ft_get_operator_token_type(char *str, int *pos);

#endif
