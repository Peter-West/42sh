/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 23:18:33 by rfrey             #+#    #+#             */
/*   Updated: 2014/02/06 23:58:52 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_list			*ft_listcreate(void *data)
{
	t_list	*new;

	new = NULL;
	new = (t_list *)malloc(sizeof(*new));
	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}
