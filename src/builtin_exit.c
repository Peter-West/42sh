/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:49:47 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/27 19:21:15 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh42.h"
#include "builtin.h"
#include "parse.h"
#include "error.h"
#include "libft.h"
#include "ft_term.h"

static int		ft_exit_check_value(char *value)
{
	int			i;

	i = 0;
	while (value[i] != '\0')
	{
		if (!ft_isdigit(value[i++]))
			return (255);
	}
	return (1);
}

void			ft_exit(t_cmd *cmd)
{
	int			a;

	a = EXIT_SUCCESS;
	if (cmd && cmd->args[1])
	{
		if ((a = ft_exit_check_value(cmd->args[1])) == 255)
			ft_puterror("exit: numeric argument required", cmd->args[1]);
		else
			a = ft_atoi(cmd->args[1]);
	}
	else
		a = ft_last_cmd_return_value(GET_VALUE);
	if (cmd != NULL)
	{
		ft_strtabfree(cmd->envp);
		free_tree(ft_get_tree(NULL));
	}
	ft_restore_default(ft_init_term());
	ft_restaure_signal();
	exit(a);
}

void			ft_quit(void)
{
	ft_putchar('\n');
	ft_exit(NULL);
}
