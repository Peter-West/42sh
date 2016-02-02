/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:30:29 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/22 18:31:59 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_strtabcpy(char **tab)
{
	char	**cpy;
	int		size;
	int		i;

	size = ft_strtabsize(tab);
	if (!((cpy = (char **)malloc(sizeof(char *) * (size + 1)))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!((cpy[i] = ft_strdup(tab[i]))))
			return (NULL);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
