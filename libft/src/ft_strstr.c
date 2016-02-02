/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 16:38:08 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/12 16:38:50 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strstr(const char *s1, const char *s2)
{
	unsigned int			i;

	if (s2 == NULL || *s2 == '\0')
		return ((char *)s1);
	if (s1 == NULL || *s1 == '\0')
		return (NULL);
	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (ft_strstr(&s1[1], s2));
		else
			i++;
	}
	return ((char *)s1);
}
