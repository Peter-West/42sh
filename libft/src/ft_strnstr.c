/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:40:52 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/12 16:42:38 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;

	if (s2 == NULL || *s2 == '\0')
		return ((char *)s1);
	if (s1 == NULL || *s1 == '\0')
		return (NULL);
	i = 0;
	while (s2[i] != '\0')
	{
		if (i >= n)
			return (NULL);
		if (s1[i] != s2[i])
			return (ft_strnstr(&s1[1], s2, n - 1));
		else
			i++;
	}
	return ((char *)s1);
}
