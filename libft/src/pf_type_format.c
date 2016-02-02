/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_type_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 21:46:53 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 18:05:56 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		ft_fchar(char c, int *cnt, int *format)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = c;
	ft_putfield(str, format, cnt);
}

void		ft_fstring(char *str, int *cnt, int *format)
{
	if (format[ATTR_HAVEPREC])
		str = ft_strsub(str, 0, format[ATTR_PRECVALUE]);
	else
		str = ft_strdup(str);
	ft_putfield(str, format, cnt);
}

void		ft_fint(int n, int *cnt, int *format)
{
	char	*str;

	str = ft_generate_int_str(n, format);
	if (format[ATTR_HAVEPREC])
	{
		if (format[ATTR_PRECVALUE] == 0 && n == 0)
			str = ft_strnew(0);
		else
			str = ft_fill_zero(str, format);
	}
	ft_putfield(str, format, cnt);
}

char		*ft_generate_int_str(int n, int *format)
{
	char	*str;

	if (format[ATTR_SUBTYPE] == 'o')
	{
		str = ft_itobase((unsigned int)n, 8);
		if (format[ATTR_SHARP])
			str = ft_addoctalprefix(&str);
		return (str);
	}
	if (format[ATTR_SUBTYPE] == 'x' || format[ATTR_SUBTYPE] == 'X')
	{
		str = ft_itobase((unsigned int)n, 16);
		if (format[ATTR_SHARP])
			str = ft_addhexaprefix(&str);
		if (format[ATTR_SUBTYPE] == 'X')
			str = ft_toupperstr(str);
		return (str);
	}
	if (n < 0)
	{
		n *= -1;
		if (format[ATTR_SUBTYPE] != 'u')
			format[ATTR_ISNEG] = 1;
	}
	return (str = ft_itoa((int)n));
}

void		ft_fdouble(double d, int *cnt, int *format)
{
	int		width;

	width = format[ATTR_WIDTH];
	d++;
	width++;
	ft_putstr("<double>");
	(*cnt)++;
}
