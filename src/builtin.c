/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 16:37:23 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/21 17:46:20 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "builtin.h"
#include "libft.h"
#include "error.h"

static void			ft_free_builtins(t_builtin **builtins)
{
	int		i;

	i = 0;
	while (i < BUILTIN_NBR)
	{
		free(builtins[i]);
		++i;
	}
	free(builtins);
}

static t_builtin	**ft_init_builtins(void)
{
	t_builtin		**builtins;
	int				i;

	i = 0;
	if ((!(builtins = (t_builtin**)malloc(sizeof(t_builtin*) * BUILTIN_NBR))))
		ft_error(ERR_MALLOC);
	while (i < BUILTIN_NBR)
	{
		if ((!(builtins[i] = (t_builtin*)malloc(sizeof(t_builtin)))))
			ft_error(ERR_MALLOC);
		++i;
	}
	return (builtins);
}

static t_builtin	**ft_get_builtins(void)
{
	t_builtin		**builtins;

	builtins = ft_init_builtins();
	builtins[0]->label = "cd";
	builtins[0]->func = ft_cd;
	builtins[1]->label = "setenv";
	builtins[1]->func = ft_setenv;
	builtins[2]->label = "unsetenv";
	builtins[2]->func = ft_unsetenv;
	builtins[3]->label = "env";
	builtins[3]->func = ft_env;
	builtins[4]->label = "exit";
	builtins[4]->func = ft_exit;
	builtins[5]->label = "echo";
	builtins[5]->func = ft_echo;
	return (builtins);
}

int					ft_exec_builtin(t_cmd *cmd)
{
	t_builtin		**builtins;
	int				i;
	void			(*exec)(t_cmd *);

	builtins = ft_get_builtins();
	i = 0;
	while (i < BUILTIN_NBR)
	{
		if (ft_strequ(cmd->cmd, builtins[i]->label))
		{
			exec = builtins[i]->func;
			ft_free_builtins(builtins);
			exec(cmd);
			return (1);
		}
		i++;
	}
	ft_free_builtins(builtins);
	return (0);
}

int					ft_is_builtin(t_cmd *cmd)
{
	t_builtin		**builtins;
	int				i;

	builtins = ft_get_builtins();
	i = 0;
	while (i < BUILTIN_NBR)
	{
		if (ft_strequ(cmd->cmd, builtins[i]->label)
			&& !ft_strequ(cmd->cmd, "env"))
		{
			ft_free_builtins(builtins);
			return (1);
		}
		i++;
	}
	ft_free_builtins(builtins);
	return (0);
}
