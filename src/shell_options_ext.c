/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_options_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 23:26:16 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/21 22:47:38 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell_options.h"

int				ft_setoptions(t_options *options, char **args)
{
	int			i;
	int			j;

	i = 0;
	while (args[i] && args[i][0] == '-')
	{
		j = 1;
		while (args[i][j])
		{
			ft_optset(options, args[i][j]);
			j++;
		}
		i++;
	}
	return (i);
}

void			ft_optfree(t_options *options)
{
	int			i;

	i = 0;
	while (options->options[i])
	{
		free(options->options[i]);
		++i;
	}
	free(options->options);
	free(options);
}

int				ft_optunset(t_options *options, char opt)
{
	int			i;

	i = 0;
	while (options->options[i])
	{
		if (options->options[i]->name == opt)
		{
			options->options[i]->isset = 0;
			return (1);
		}
		i++;
	}
	return (0);
}
