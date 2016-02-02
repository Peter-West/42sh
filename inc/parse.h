/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 00:22:19 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/27 19:12:11 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "libft.h"
# include "sh42.h"
# include "lexer.h"

typedef enum		e_type_node
{
	TN_PIPE,
	TN_AND,
	TN_OR,
	TN_SEMICOL,
	TN_CMD
}					t_type_node;

typedef struct		s_node
{
	void			*data;
	struct s_node	*left;
	struct s_node	*right;
	t_type_node		type;
}					t_node;

typedef struct		s_arg_parse
{
	t_list	*tokens;
	t_node	*tree;
	t_node	*pipeline;
	t_node	*boolline;
	char	***envp;
	t_cmd	*cmd;
}					t_arg_parse;

int					parse_cmd(t_list *tokens, char ***envp);
t_token				*get_tok();
t_token_type		get_type(t_list *lst);
int					is_type(t_list **tokens, t_token_type to_compare);
void				set_arg_parse(t_arg_parse *dst, t_arg_parse *src);
void				restore(t_arg_parse *dst, t_arg_parse *svg);
t_token_type		get_type(t_list *lst);
int					is_type(t_list **tokens, t_token_type to_compare);
t_node				*ft_btinitnode_syntax(void *data, t_type_node type);
int					rule_cmd(t_arg_parse *arg);
int					rule_boolline(t_arg_parse *arg);
int					rule_pipeline(t_arg_parse *arg);
int					rule_semi_col(t_arg_parse *arg);
int					rule_paradigm(t_arg_parse *arg);
int					rule_redir_in(t_arg_parse *arg);
int					rule_redir_out(t_arg_parse *arg);
t_node				*create_root(t_node *left, t_node *right, t_type_node type);
t_node				*generate_pipe(t_arg_parse *arg);
t_node				*generate_boolline(t_arg_parse *arg, t_token_type tok_type);
t_node				*generate_semicol(t_arg_parse *arg);
t_node				*ft_btinitnode_syntax(void *data, t_type_node type);
void				ft_print_syntax_tree(t_node *tree);
void				ft_put_node(t_node *node);
void				ft_put_node_type(t_type_node type);
t_cmd				*ft_build_cmd(t_arg_parse *arg, t_list *start);
t_node				*ft_btinitnode(void *data);
t_node				**ft_get_tree(t_node *set);
void				free_tree(t_node **tree);

#endif
