/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 22:22:48 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 16:50:01 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shell_options.h"

t_options		*ft_optinit(int n)
{
	t_options	*options;
	int			i;

	if (!((options = (t_options *)malloc(sizeof(t_options)))))
		return (NULL);
	if (!((options->options = (t_opt **)malloc(sizeof(t_opt *) * (n + 1)))))
		return (NULL);
	i = 0;
	while (i < n + 1)
	{
		options->options[i] = NULL;
		i++;
	}
	return (options);
}

t_opt			*ft_optcreate(char opt)
{
	t_opt		*option;

	if (!((option = (t_opt *)malloc(sizeof(t_opt)))))
		return (NULL);
	option->name = opt;
	option->isset = 0;
	return (option);
}

void			ft_optadd(t_options *options, t_opt *opt)
{
	int			i;

	i = 0;
	while (options->options[i])
		i++;
	options->options[i] = opt;
}

int				ft_optisset(t_options *options, char opt)
{
	int			i;

	i = 0;
	while (options->options[i])
	{
		if (options->options[i]->name == opt)
			return (options->options[i]->isset);
		i++;
	}
	return (0);
}

int				ft_optset(t_options *options, char opt)
{
	int			i;

	i = 0;
	while (options->options[i])
	{
		if (options->options[i]->name == opt)
		{
			options->options[i]->isset = 1;
			return (1);
		}
		i++;
	}
	return (0);
}
