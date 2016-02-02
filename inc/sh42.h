/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:33:06 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 17:55:47 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H
# define SH42_H
# include "list.h"

typedef enum		e_redir_type
{
	RED_LEFT_1,
	RED_LEFT_2,
	RED_RIGHT_1,
	RED_RIGHT_2
}					t_redir_type;

typedef struct		s_redir
{
	t_redir_type	type;
	char			*filename;
}					t_redir;

typedef struct		s_cmd
{
	char			*cmd;
	char			**args;
	char			***envp;
	t_redir			**redir;
	char			*fullpath;
}					t_cmd;

void				ft_freecmd(t_cmd **cmd);
char				**ft_getenvpath(char **envp);
void				ft_path_canonize(char **path);
char				*ft_check_file(char *path);
void				ft_clear(t_list *tokens, char ***envp);
char				*ft_get_fullpath_cmd(t_cmd *cmd);
void				ft_cmdnotfound(t_cmd *cmd);
char				*ft_cmdexist(char *path, char *cmd);
char				*ft_get_in_path_env(t_cmd *cmd);
char				*ft_get_in_absolute_path(t_cmd *cmd);
void				ft_exec_cmd(t_cmd *cmd);
t_cmd				*ft_cmd_init(char **args, char ***envp);
void				ft_freecmd(t_cmd **cmd);
t_cmd				*ft_create_cmd(char ***envp);
void				ft_exec(char ***envp);
void				ft_prompt(char **envp);
void				ft_parse_and_exec(t_list *tokens, char ***envp);
void				ft_resolve(t_list **cmds);
t_cmd				*ft_check_builtin(t_list **cmds);
int					ft_exec_redir(t_cmd *cmd, int redir);
void				ft_free_redir(t_redir *redir);
t_redir				*ft_init_redir(char *filename, t_redir_type type);
int					*get_pid_running_proc(void);
void				ft_prompt(char **envp);
void				free_tokens(t_list **ptr_tokens);

#endif
