/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabrm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 17:42:18 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/28 16:52:18 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_strtabrm(char ***tab, int index)
{
	char	**new;
	int		size;
	int		i;
	int		j;

	size = ft_strtabsize(*tab);
	if (!((new = (char **)malloc(sizeof(char *) * (size)))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (i != index)
		{
			new[j] = (*tab)[i];
			j++;
		}
		i++;
	}
	new[j] = NULL;
	free((*tab)[index]);
	free(*tab);
	*tab = new;
	return (new);
}
