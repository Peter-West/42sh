/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:29:12 by rfrey             #+#    #+#             */
/*   Updated: 2013/12/23 14:21:42 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		neg;

	if (str == NULL)
		return (0);
	i = 0;
	n = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]) || str[i] == 9)
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	n *= neg;
	return (n);
}
