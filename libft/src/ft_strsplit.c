/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 23:48:30 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 18:04:27 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_count_word(char const *s, char c)
{
	int		n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		while (*s != c && *s)
			s++;
		n++;
	}
	return (n);
}

static char		**ft_put_word(char const *s, char c, int w, char **res)
{
	int		i;
	int		pos;
	int		len;

	i = 0;
	pos = 0;
	while (i < w)
	{
		while (s[pos] == c)
			pos++;
		len = 0;
		while (s[pos + len] != c && s[pos + len])
			len++;
		if ((!(res[i++] = ft_strsub(s, pos, len))))
			return (NULL);
		pos += len;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		w;

	res = NULL;
	if (s)
	{
		w = ft_count_word(s, c);
		if ((res = (char **)malloc(sizeof(char *) * (w + 1))))
		{
			if (ft_put_word(s, c, w, res))
				res[w] = NULL;
			else
				return (NULL);
		}
	}
	return (res);
}
