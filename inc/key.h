/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 15:56:25 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 17:36:47 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H

# define KEY_H
# define KEY_SIMPLE key[1] == 0 && key [2] == 0 && key[3] == 0
# define KEY_UP key[0] == 27 && key[1] == 91 && key[2] == 65 && key[3] == 0
# define KEY_DOWN key[0] == 27 && key[1] == 91 && key[2] == 66 && key[3] == 0
# define KEY_LEFT key[0] == 27 && key[1] == 91 && key[2] == 68 && key[3] == 0
# define KEY_RIGHT key[0] == 27 && key[1] == 91 && key[2] == 67 && key[3] == 0
# define KEY_SP key[0] == 32 && KEY_SIMPLE
# define KEY_RET key[0] == 10 && KEY_SIMPLE
# define KEY_BSP key[0] == 127 && KEY_SIMPLE
# define KEY_ESC key[0] == 27 && KEY_SIMPLE
# define KEY_DEL key[0] == 27 && key[1] == 91 && key[2] == 51 && key[3] == 126
# define KEY_HOME key[0] == 27 && key[1] == 91 && key[2] == 72 && key[3] == 0
# define KEY_END key[0] == 27 && key[1] == 91 && key[2] == 70 && key[3] == 0
# define KEY_CO key[0] == -61 && key[1] == -89 && key[2] == 0 && key[3] == 0
# define KEY_CU key[0] == -30 && key[1] == -119 && key[2] == -120 && key[3] == 0
# define KEY_PA key[0] == -30 && key[1] == -120 && key[2] == -102 && key[3] == 0
# define KEY_PRINTABLE key[0] >= ' ' && key [0] < '~' && KEY_SIMPLE
# define KEY_SHIFT key[0] == 27 && key[1] == 91 && key[2] == 49 && key[3] == 59
# define KEY_SEL key[0] == -61 && key[1] == -97 && key[2] == -0 && key[3] == 0
# define KEY_WNEXT key[0] == 50 && key[1] == 67 && key[2] == 0 && key[3] == 0
# define KEY_WPREV key[0] == 50 && key[1] == 68 && key[2] == 0 && key[3] == 0
# define KEY_CTRLD key[0] == 4 && key[1] == 0 && key[2] == 0 && key[3] == 0
# define KEY_TAB key[0] == 9 && key[1] == 0 && key[2] == 0 && key[3] == 0

#endif
