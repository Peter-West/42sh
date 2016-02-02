/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:45:08 by rfrey             #+#    #+#             */
/*   Updated: 2013/11/25 20:37:18 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	if (s == NULL)
		return (NULL);
	while (n > 0)
	{
		if (*(unsigned char *)s++ == (unsigned char)c)
		{
			s--;
			return ((void *)(s));
		}
		n--;
	}
	return (NULL);
}
