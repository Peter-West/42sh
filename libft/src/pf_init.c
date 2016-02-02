/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 13:40:47 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/27 18:25:03 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int			*ft_init_format(void)
{
	int		i;
	int		*format;

	if (!((format = (int *)malloc(sizeof(int) * ATTRNBR))))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < ATTRNBR)
		format[i++] = 0;
	return (format);
}
