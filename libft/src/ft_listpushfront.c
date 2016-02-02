/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpushfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:25:25 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/10 14:51:37 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void			ft_listpushfront(t_list **list, void *data)
{
	t_list	*new;

	if (list != NULL)
	{
		new = ft_listcreate(data);
		if (new != NULL)
		{
			if (*list != NULL)
				new->next = *list;
			*list = new;
		}
	}
}
