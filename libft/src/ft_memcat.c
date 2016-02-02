/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 17:56:42 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/05 18:28:36 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			*ft_memcat(void *s1, void *s2, int len1, int len2)
{
	unsigned char	*ret;
	int				i;
	int				j;

	if (len1 + len2 == 0)
		return (NULL);
	if ((ret = (unsigned char *)malloc(len1 + len2)))
	{
		i = 0;
		while (i < len1)
			ret[i++] = *(unsigned char *)s1++;
		j = 0;
		while (j < len2)
		{
			ret[i++] = *(unsigned char *)s2++;
			j++;
		}
	}
	return ((void *)ret);
}
