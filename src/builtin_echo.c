/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 23:29:10 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/21 18:19:11 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"

int				ft_last_cmd_return_value(int set)
{
	static int	value = 0;

	if (set != GET_VALUE)
		value = set;
	return (value);
}

static void		ft_put_arg(char *arg, char **env)
{
	char		*var;

	if (arg[0] == '$' && arg[1])
	{
		if (arg[1] == '?')
		{
			ft_putnbr(ft_last_cmd_return_value(GET_VALUE));
			ft_putstr(&arg[2]);
		}
		var = ft_getenv(env, &arg[1]);
		if (var)
			ft_putstr(var);
	}
	else
		ft_putstr(arg);
}

void			ft_echo(t_cmd *cmd)
{
	int			i;
	int			opt_n;

	opt_n = 0;
	i = 1;
	if (cmd->args[1] && cmd->args[1][0] == '-' && cmd->args[1][1] == 'n')
	{
		++opt_n;
		++i;
	}
	while (cmd->args[i])
	{
		ft_put_arg(cmd->args[i], *cmd->envp);
		if (cmd->args[i + 1])
			ft_putstr(" ");
		i++;
	}
	if (!opt_n)
		ft_putchar('\n');
}
