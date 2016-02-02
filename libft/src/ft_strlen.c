/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 10:52:42 by rfrey             #+#    #+#             */
/*   Updated: 2013/11/25 20:19:12 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t			ft_strlen(const char *str)
{
	size_t		count;

	if (str != NULL)
	{
		count = 0;
		while (str[count] != '\0')
			count++;
		return (count);
	}
	return (0);
}
