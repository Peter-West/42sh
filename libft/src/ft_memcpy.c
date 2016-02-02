/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:14:34 by rfrey             #+#    #+#             */
/*   Updated: 2013/11/25 20:35:50 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	void	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = s1;
	while (n > 0)
	{
		*(unsigned char *)s1++ = *(unsigned char *)s2++;
		n--;
	}
	return (ret);
}
