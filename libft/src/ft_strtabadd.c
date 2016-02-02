/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 17:42:18 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/22 19:06:37 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_strtabadd(char ***tab, char *add)
{
	char	**new;
	int		size;
	int		i;

	size = ft_strtabsize(*tab);
	if (!((new = (char **)malloc(sizeof(char *) * (size + 2)))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = (*tab)[i];
		i++;
	}
	new[i] = add;
	new[i + 1] = NULL;
	free(*tab);
	*tab = new;
	return (new);
}
