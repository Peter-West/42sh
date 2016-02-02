/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listgetn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 21:32:42 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/20 16:34:13 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_list			*ft_listgetn(t_list *list, unsigned int n)
{
	unsigned int			i;

	if (!list || n < 1)
		return (NULL);
	i = 1;
	while (i < n)
	{
		list = list->next;
		if (!list)
			return (NULL);
		++i;
	}
	return (list);
}
