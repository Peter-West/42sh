/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:33:06 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/27 17:32:01 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# define BUILTIN_NBR 6
# define GET_VALUE -42424242
# include "sh42.h"
# include "shell_options.h"

typedef struct		s_builtin
{
	char			*label;
	void			(*func)(t_cmd *);
}					t_builtin;

int					ft_is_builtin(t_cmd *cmd);
int					ft_exec_builtin(t_cmd *cmd);
int					ft_change_pwd(char *path, t_cmd *cmd);
void				ft_cd(t_cmd *cmd);
t_options			*ft_getcdoptions(void);
char				*ft_catpath(char *path_l, char *path_r);
void				ft_env(t_cmd *cmd);
char				**ft_get_envp_cpy(t_cmd *cmd, int *i);
char				*ft_getenv(char **envp, char *get);
void				ft_setenv(t_cmd *cmd);
void				ft_unsetenv(t_cmd *cmd);
char				*ft_envcreate(char *name, char *value);
int					ft_getenvindex(char **envp, char *find);
void				ft_update_env(char ***envp, char *name, char *value);
void				ft_exit(t_cmd *cmd);
int					ft_last_cmd_return_value(int set);
void				ft_quit(void);
void				ft_echo(t_cmd *cmd);
int					ft_last_cmd_return_value(int set);
int					ft_set_cd_options(t_options *options, char **args);
void				ft_replace_link(char **path);
char				*ft_check_in_cdpath(char *curpath, char **envp);
char				**get_envp(char **envp2);

#endif
