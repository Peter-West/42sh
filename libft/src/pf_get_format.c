/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:40:31 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/12 17:14:47 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_get_type(const char *end, int *format)
{
	format[ATTR_SUBTYPE] = end[0];
	if (*end == 'c')
		return (format[ATTR_TYPE] = CHAR);
	else if (*end == 's')
		return (format[ATTR_TYPE] = STRING);
	else if (ft_is_int(end[0]))
		return (format[ATTR_TYPE] = INT);
	else if (ft_is_float(end[0]))
		return (format[ATTR_TYPE] = DOUBLE);
	else
		return (format[ATTR_TYPE] = TYPE_ERROR);
}

void		ft_getattr(const char **str, int *format)
{
	while (ft_strchr(ATTR, *(*str)))
	{
		if (*(*str) == '#')
			format[ATTR_SHARP] = 1;
		else if (*(*str) == '0')
			format[ATTR_ZERO] = 1;
		else if (*(*str) == ' ')
			format[ATTR_SPACE] = 1;
		else if (*(*str) == '+')
			format[ATTR_PLUS] = 1;
		else if (*(*str) == '\'')
			format[ATTR_APOST] = 1;
		else if (*(*str) == '-')
			format[ATTR_DASH] = 1;
		(*str)++;
	}
}
