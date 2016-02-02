/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:50:18 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 18:06:24 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;
	char	*start;
	int		*format;

	if (!str)
		exit(EXIT_FAILURE);
	cnt = 0;
	format = NULL;
	va_start(ap, str);
	while ((ft_parse(&cnt, &start, &str, &format)))
	{
		ft_convert(ap, &cnt, format);
		str++;
	}
	va_end(ap);
	if (format)
		free(format);
	return (cnt);
}

void		ft_convert(va_list ap, int *cnt, int *format)
{
	if (format[ATTR_TYPE] == CHAR)
		ft_fchar((char)va_arg(ap, int), cnt, format);
	else if (format[ATTR_TYPE] == STRING)
		ft_fstring(va_arg(ap, char*), cnt, format);
	else if (format[ATTR_TYPE] == INT)
		ft_fint(va_arg(ap, int), cnt, format);
	else if (format[ATTR_TYPE] == DOUBLE)
		ft_fdouble(va_arg(ap, double), cnt, format);
}
