/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:26:17 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/15 19:31:31 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void			ft_listclear(t_list **list)
{
	t_list	*tmp;

	if (list != NULL && *list != NULL)
	{
		tmp = (*list)->next;
		while (tmp)
		{
			tmp = (*list)->next;
			free((*list)->data);
			free(*list);
			*list = tmp;
		}
	}
}
