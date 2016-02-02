/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:53:20 by rfrey             #+#    #+#             */
/*   Updated: 2014/02/06 23:59:47 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ret;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	if ((!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1)))))
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = f(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
