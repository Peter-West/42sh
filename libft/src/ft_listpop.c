/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:23:21 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/17 22:53:40 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void			*ft_listpop(t_list **list)
{
	t_list	*tmp;
	void	*data;

	data = NULL;
	if (list != NULL)
	{
		if (*list != NULL)
		{
			tmp = (*list)->next;
			data = (*list)->data;
			free(*list);
			*list = tmp;
		}
	}
	return (data);
}
