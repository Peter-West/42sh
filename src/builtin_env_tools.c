/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:31:56 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/11 22:14:10 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "builtin.h"
#include "libft.h"
#include "error.h"

void		ft_update_env(char ***envp, char *name, char *value)
{
	int		index;

	if (ft_strchr(name, '='))
	{
		ft_putendl_fd("Setenv : Syntax Error.", 2);
		return ;
	}
	if ((index = ft_getenvindex(*envp, name)) != -1)
	{
		free((*envp)[index]);
		(*envp)[index] = ft_envcreate(name, value);
	}
	else
		ft_strtabadd(envp, ft_envcreate(name, value));
}

char		*ft_envcreate(char *name, char *value)
{
	char	*new;
	int		len;

	len = ft_strlen(name) + 2;
	if (value)
		len += ft_strlen(value);
	if (!((new = (char *)malloc(sizeof(char) * len))))
		ft_error(ERR_MALLOC);
	ft_strcpy(new, name);
	ft_strcat(new, "=");
	if (value)
		ft_strcat(new, value);
	return (new);
}

int			ft_getenvindex(char **envp, char *find)
{
	int		i;
	int		len;

	if (!envp)
		return (-1);
	len = ft_strlen(find);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(find, envp[i], len) && envp[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}
