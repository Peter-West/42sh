/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:43:41 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/10 15:34:38 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	if ((str = malloc(size + 1)))
	{
		i = 0;
		while (i < size + 1)
			str[i++] = '\0';
	}
	return (str);
}
