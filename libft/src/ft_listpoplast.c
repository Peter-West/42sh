/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpoplast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/23 19:11:37 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/23 19:30:58 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

void		*ft_listpoplast(t_list **list)
{
	t_list	*previous;
	t_list	*current;
	void	*data;

	if (!*list)
		return (NULL);
	if (!(*list)->next)
	{
		data = (*list)->data;
		free(*list);
		*list = NULL;
		return (data);
	}
	previous = *list;
	current = (*list)->next;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	data = current->data;
	free(current);
	previous->next = NULL;
	return (data);
}
