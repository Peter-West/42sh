/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:50:31 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 18:03:09 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_pow(int nb, int power)
{
	if (!power)
		return (1);
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	return (nb * ft_pow(nb, power - 1));
}

char			*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			num;
	int			exp;

	num = n;
	if (n < 0)
		num *= -1;
	exp = 0;
	while (num / ft_pow(10, exp) > 9)
		exp++;
	if ((str = ft_strnew(sizeof(char) * (exp + (n < 0) + 2))))
	{
		i = 0;
		if (n < 0)
			str[i++] = '-';
		while (exp >= 0)
		{
			str[i++] = num / ft_pow(10, exp) + 48;
			num %= ft_pow(10, exp--);
		}
	}
	return (str);
}
