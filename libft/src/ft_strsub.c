/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:19:37 by rfrey             #+#    #+#             */
/*   Updated: 2013/11/26 23:31:04 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	str = NULL;
	if (s)
	{
		if ((str = malloc(len + 1)))
		{
			i = 0;
			while (i < len)
			{
				str[i] = s[start + i];
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}
