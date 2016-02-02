/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 22:28:34 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/18 22:40:04 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdelchar(char *str, char *to_remove)
{
	int		len;
	char	*ret;
	char	*tmp;

	tmp = str;
	len = ft_strlen(str);
	while (*str)
	{
		if (ft_strchr(to_remove, *str))
			--len;
		++str;
	}
	if ((!(ret = ft_strnew(len))))
		return (NULL);
	while (*tmp)
	{
		if (!ft_strchr(to_remove, *tmp))
		{
			*ret = *tmp;
			++ret;
		}
		++tmp;
	}
	return (ret);
}
