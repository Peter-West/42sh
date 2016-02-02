/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:36:46 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/12 17:24:15 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (n)
	{
		if ((*(unsigned char *)s1++ = *(unsigned char *)s2++) == c)
			return (s1);
		n--;
	}
	return (NULL);
}
