/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 18:19:17 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 18:21:07 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse.h"
#include "libft.h"

t_node	*ft_btinitnode(void *data)
{
	t_node		*new_node;

	if ((!(new_node = (t_node *)malloc(sizeof(t_node)))))
		return (NULL);
	ft_bzero(new_node, sizeof(t_node));
	new_node->data = data;
	return (new_node);
}
