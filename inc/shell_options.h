/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_options.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 22:55:06 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 17:39:01 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_OPTIONS_H
# define SHELL_OPTIONS_H

typedef struct	s_option
{
	char		name;
	int			isset;
}				t_opt;

typedef struct	s_options
{
	t_opt		**options;
}				t_options;

t_options		*ft_optinit(int n);
t_opt			*ft_optcreate(char opt);
void			ft_optadd(t_options *options, t_opt *opt);
int				ft_optisset(t_options *options, char opt);
int				ft_optset(t_options *options, char opt);
int				ft_optunset(t_options *options, char opt);
int				ft_setoptions(t_options *options, char **args);
void			ft_optfree(t_options *options);

#endif
