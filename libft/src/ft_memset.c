/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:45:39 by rfrey             #+#    #+#             */
/*   Updated: 2013/11/25 20:34:55 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memset(void *b, int c, size_t len)
{
	void	*ptr;

	if (b == NULL)
		return (NULL);
	ptr = b;
	while (len > 0)
	{
		*(unsigned char *)ptr++ = (unsigned char)c;
		len--;
	}
	return (b);
}
