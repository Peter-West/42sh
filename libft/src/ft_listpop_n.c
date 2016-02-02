/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpop_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 20:12:13 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/25 20:29:06 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void		*ft_listpop_n(t_list **list, int n)
{
	int		i;
	t_list	*tmp;
	t_list	*prev;

	tmp = *list;
	if (n < 1)
		return (NULL);
	if (n == 1)
	{
		*list = tmp->next;
		return (tmp->data);
	}
	i = 1;
	while (i < n)
	{
		prev = tmp;
		tmp = tmp->next;
		if (!tmp)
			return (NULL);
		++i;
	}
	prev->next = tmp->next;
	return (tmp->data);
}
