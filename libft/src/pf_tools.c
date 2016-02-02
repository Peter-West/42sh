/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:41:56 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/12 17:18:32 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int			ft_is_int(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

int			ft_is_float(char c)
{
	if (c == 'e' || c == 'f' || c == 'g' || c == 'a')
		return (1);
	if (c == 'E' || c == 'F' || c == 'G' || c == 'A')
		return (1);
	return (0);
}

const char	*ft_skip(const char *str, char *skipchr)
{
	int		i;

	i = 0;
	while (ft_strchr(skipchr, str[i]))
		i++;
	return (&(str[i]));
}

char		*ft_toupperstr(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
	{
		*str = (char)ft_toupper(*str);
		str++;
	}
	return (tmp);
}

char		*ft_fill_zero(char *str, int *format)
{
	char	*tmp;
	int		n;
	int		len;
	int		i;

	len = ft_strlen(str);
	n = format[ATTR_PRECVALUE] - len;
	if (n > 0)
	{
		tmp = str;
		str = ft_strnew(len + n);
		i = 0;
		while (i < n)
			str[i++] = '0';
		ft_strcpy(&str[i], tmp);
		free(tmp);
	}
	return (str);
}
