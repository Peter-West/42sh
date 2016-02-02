/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:52:01 by rfrey             #+#    #+#             */
/*   Updated: 2013/11/25 20:24:31 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		while (s1[i] == s2[i])
		{
			if (s1[i] == '\0')
				return (0);
			i++;
			if (i == n)
			{
				i--;
				break ;
			}
		}
		return (s1[i] - s2[i]);
	}
	return (0);
}
