/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 20:55:46 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/13 01:11:10 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	ft_getchar(int n)
{
	if (n >= 0 && n <= 9)
		return (n + 48);
	else if (n > 9 && n < 36)
		return (n + 87);
	return ('?');
}

char		*ft_itobase(unsigned int n, unsigned int b)
{
	char	*str;
	char	*tmp;
	int		i;
	int		len;

	len = sizeof(unsigned int) * 8;
	str = ft_strnew(len);
	ft_memset(str, ' ', len);
	i = 1;
	while (n >= b)
	{
		str[len - i] = ft_getchar(n % b);
		n = n / b;
		i++;
	}
	str[len - i] = ft_getchar(n);
	tmp = str;
	str = ft_strtrim(str);
	free(tmp);
	return (str);
}

char		*ft_addoctalprefix(char **str)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*str) + 1);
	tmp[0] = '0';
	ft_strcpy(&tmp[1], *str);
	free(*str);
	*str = tmp;
	return (*str);
}

char		*ft_addhexaprefix(char **str)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*str) + 2);
	tmp[0] = '0';
	tmp[1] = 'x';
	ft_strcpy(&tmp[2], *str);
	free(*str);
	*str = tmp;
	return (*str);
}
