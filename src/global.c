/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 22:07:10 by gbersac           #+#    #+#             */
/*   Updated: 2014/03/27 18:16:00 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "sh42.h"

char		**get_envp(char **envp2)
{
	static char	**envp = NULL;

	if (envp2 != NULL)
		envp = ft_strtabcpy(envp2);
	return (envp);
}

int			*get_pid_running_proc(void)
{
	static int	pid = 0;

	return (&pid);
}
