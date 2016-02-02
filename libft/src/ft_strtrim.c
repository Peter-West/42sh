/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:44:39 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 18:05:22 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	str = NULL;
	if (s)
	{
		start = 0;
		while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
			start++;
		if (!s[start])
			return (ft_strnew(0));
		end = ft_strlen(s) - 1;
		while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
			end--;
		if ((str = (ft_strnew(sizeof(char) * (end - start + 2)))))
		{
			i = 0;
			while (start <= end)
				str[i++] = s[start++];
		}
	}
	return (str);
}
