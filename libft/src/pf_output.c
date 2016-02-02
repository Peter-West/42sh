/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:41:11 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 18:05:43 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

void		ft_fill_field(int n, int *f)
{
	int		i;
	char	c;

	if (f[ATTR_DASH])
		c = ' ';
	else if (f[ATTR_ZERO] && f[ATTR_TYPE] == DOUBLE)
		c = '0';
	else if (f[ATTR_ZERO] && f[ATTR_TYPE] == INT && !f[ATTR_HAVEPREC])
		c = '0';
	else
		c = ' ';
	i = 0;
	while (i++ < n)
		ft_putchar(c);
}

void		ft_putfield(char *str, int *format, int *cnt)
{
	int		len;

	len = ft_strlen(str);
	if (format[ATTR_ISNEG] || format[ATTR_SPACE] || format[ATTR_PLUS])
		len++;
	if (format[ATTR_ZERO])
		ft_putsign(format);
	if (format[ATTR_DASH])
		ft_putsignedstr(str, format);
	ft_fill_field(format[ATTR_WIDTH] - len, format);
	if (!format[ATTR_DASH])
		ft_putsignedstr(str, format);
	if (str)
		free(str);
	if (format[ATTR_WIDTH] < len)
		(*cnt) += len;
	else
		(*cnt) += format[ATTR_WIDTH];
}

int			ft_putsign(int *f)
{
	if (f[ATTR_ISNEG])
		ft_putchar('-');
	else if (f[ATTR_PLUS] && (f[ATTR_TYPE] == INT || f[ATTR_TYPE] == DOUBLE))
		ft_putchar('+');
	else if (f[ATTR_SPACE] && (f[ATTR_TYPE] == INT || f[ATTR_TYPE] == DOUBLE))
		ft_putchar(' ');
	else
		return (0);
	return (1);
}

void		ft_putsignedstr(char *str, int *format)
{
	if (!format[ATTR_ZERO])
		ft_putsign(format);
	ft_putstr(str);
}
