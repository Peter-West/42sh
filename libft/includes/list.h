/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 23:07:20 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 17:59:57 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, int content_size);
t_list				*ft_listcreate(void *data);
void				ft_listpushback(t_list **list, void *data);
void				ft_listpushfront(t_list **list, void *data);
void				*ft_listpop(t_list **list);
void				*ft_listpoplast(t_list **list);
void				ft_listclear(t_list **list);
int					ft_listcnt(t_list *list);
t_list				*ft_listgetn(t_list *list, unsigned int n);
void				*ft_listpop_n(t_list **list, int n);

#endif
