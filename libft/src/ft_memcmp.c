/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:48:54 by rfrey             #+#    #+#             */
/*   Updated: 2013/11/25 20:37:50 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (n > 0)
		{
			if (*(unsigned char *)s1 != *(unsigned char *)s2)
				return (*(unsigned char *)(s1) - *(unsigned char *)(s2));
			s1++;
			s2++;
			n--;
		}
	}
	return (0);
}
