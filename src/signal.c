/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 22:17:16 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/11 23:15:07 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <libft.h>
#include "sh42.h"
#include "builtin.h"

static void	sigint_handler(int sig)
{
	int		*pid;

	if (sig == SIGINT)
	{
		pid = get_pid_running_proc();
		if (*pid != 0)
			kill(*pid, SIGQUIT);
		else
		{
			ft_putendl("");
			ft_prompt(get_envp(NULL));
		}
	}
}

void		ft_init_signal(void)
{
	signal(SIGINT, sigint_handler);
}

void		ft_restaure_signal(void)
{
	signal(SIGINT, SIG_DFL);
}
