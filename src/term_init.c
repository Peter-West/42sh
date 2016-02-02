/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 16:35:19 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/11 22:54:19 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error.h"
#include "ft_term.h"

void				ft_restore_default(t_term *termios)
{
	char	*clipboard;

	termios->c_lflag |= (ICANON | ECHO);
	tcsetattr(0, TCSANOW, termios);
	if ((clipboard = ft_clipboard(NULL)))
		free(clipboard);
}

t_term				*ft_init_term(void)
{
	char			*term;
	t_term			*termios;

	if ((!(termios = malloc(sizeof(t_term)))))
		ft_error(ERR_MALLOC);
	if ((!(term = getenv("TERM"))))
		ft_error(ERR_TERM_NOT_FOUND);
	if (tgetent(NULL, term) != 1)
		ft_error(ERR_TERM_NOT_FOUND);
	if (tcgetattr(0, termios) == -1)
		ft_error(ERR_TERM_INIT);
	termios->c_lflag &= ~(ICANON);
	termios->c_lflag &= ~(ECHO);
	if (tcsetattr(0, TCSANOW, termios) == -1)
		ft_error(ERR_TERM_INIT);
	return (termios);
}
