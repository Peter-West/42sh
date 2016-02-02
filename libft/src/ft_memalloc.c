/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:33:50 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/06 23:59:51 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void		*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	unsigned int	i;

	if (size == 0)
		return (NULL);
	i = 0;
	if ((ptr = (unsigned char *)malloc(size)))
	{
		while (i < size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return ((void *)ptr);
}
