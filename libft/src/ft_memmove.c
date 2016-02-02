/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:54:36 by rfrey             #+#    #+#             */
/*   Updated: 2013/11/25 20:36:50 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = s1;
	if (s1 >= s2)
		return (ft_memcpy(s1, s2, n));
	while (n > 0)
	{
		*(unsigned char *)s1++ = *(unsigned char *)s2++;
		n--;
	}
	return (ret);
}
