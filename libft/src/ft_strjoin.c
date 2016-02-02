/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:33:24 by rfrey             #+#    #+#             */
/*   Updated: 2014/02/06 23:59:33 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	str = NULL;
	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		if ((str = (char *)malloc(sizeof(char) * size)))
		{
			i = 0;
			while (s1[i])
			{
				str[i] = s1[i];
				i++;
			}
			j = 0;
			while (s2[j])
				str[i++] = s2[j++];
			str[i] = '\0';
		}
	}
	return (str);
}
