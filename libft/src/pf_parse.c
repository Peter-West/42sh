/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:41:33 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/12 17:40:14 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int			ft_parse(int *cnt, char **start, const char **str, int **format)
{
	if (!*str)
		return (0);
	while (*(*str))
	{
		if (*(*str) == '%')
		{
			(*str)++;
			if (*(*str) != '%')
			{
				if (*format)
					free(*format);
				*format = ft_init_format();
				*start = (char *)(*str);
				return (ft_get_format(str, *format));
			}
		}
		ft_putchar(*(*str));
		(*str)++;
		(*cnt)++;
	}
	return (0);
}

int			ft_get_format(const char **str, int *format)
{
	ft_getattr(str, format);
	if (*(*str) == '*')
		(*str)++;
	else
	{
		format[ATTR_WIDTH] = ft_atoi(*str);
		*str = ft_skip(*str, NBR);
	}
	if (*(*str) == '.')
	{
		format[ATTR_HAVEPREC] = 1;
		(*str)++;
		if (*(*str) == '*')
			(*str)++;
		else
		{
			format[ATTR_PRECVALUE] = ft_atoi(*str);
			*str = ft_skip(*str, NBR);
		}
	}
	return (ft_get_type(*str, format));
}
