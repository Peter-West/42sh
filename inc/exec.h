/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 17:55:14 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 18:18:32 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include <sys/stat.h>
# include "parse.h"
# define MOD_RED_R1 O_WRONLY | O_CREAT | O_TRUNC
# define MOD_RED_R2 O_WRONLY | O_CREAT | O_APPEND

typedef enum	e_pipe_fd
{
	OUT,
	IN
}				t_pipe_fd;

int		ft_resolve_tree(t_node *tree);
int		ft_browse_tree(t_node *node, int *fd_read, int fd_write, int is_pl);
int		resolve_cmd(t_node *node, int *fd_read, int is_end);
int		ft_resolve_redir(t_cmd *cmd);
int		ft_resolve_redir2(t_cmd *cmd, int i);
int		ft_open_for_writing(char *filename, struct stat *infos);
int		ft_open_for_reading(char *filename, struct stat *infos);
int		ft_resolve_cmd_nofork(t_cmd *cmd);

#endif
