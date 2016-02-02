/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabinit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 21:37:07 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/11 21:53:28 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**ft_strtabinit(unsigned int n)
{
	char			**tab;
	unsigned int	i;

	if ((!(tab = (char**)malloc(sizeof(char*) * (n + 1)))))
		return (NULL);
	i = 0;
	while (i < n + 1)
	{
		tab[i] = NULL;
		++i;
	}
	return (tab);
}
