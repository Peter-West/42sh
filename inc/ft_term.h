/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 16:32:10 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 17:54:30 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_H
# define FT_TERM_H
# include <term.h>
# include <termios.h>
# include "list.h"
# define CMD_LINE_BUF 1024

typedef struct termios	t_term;

typedef struct	s_cmd_line
{
	char		*str;
	char		**envp;
	int			len;
	int			pos;
	int			sel_mode;
	int			sel_start;
	int			sel_end;
}				t_cmd_line;

typedef struct	s_historic
{
	t_list		*list;
	int			pos;
}				t_historic;

t_term			*ft_init_term(void);
void			ft_restore_default(t_term *termios);
char			*ft_get_cmd(char **envp);
int				ft_handle_key(char key[4], t_cmd_line *line, t_historic *hist);
void			ft_shift(t_cmd_line *line);
void			ft_simple_key(char key[4], t_cmd_line *line, t_historic *hist);
t_cmd_line		*ft_init_cmd_line(char **envp);
void			ft_extend_cmd_line(t_cmd_line *line);
void			ft_free_cmd_line(t_cmd_line **line);
void			ft_key_left(t_cmd_line *line);
void			ft_key_right(t_cmd_line *line);
void			ft_key_home(t_cmd_line *line);
void			ft_key_end(t_cmd_line *line);
int				ft_put_term_char(int c);
t_historic		*ft_init_historic(void);
void			ft_delete_line(t_cmd_line *line);
void			ft_key_up(t_cmd_line *line, t_historic *historic);
void			ft_key_down(t_cmd_line *line, t_historic *historic);
void			ft_next_word(t_cmd_line *line);
void			ft_prev_word(t_cmd_line *line);
void			ft_key_del(t_cmd_line *line);
void			ft_key_backdel(t_cmd_line *line);
void			ft_add_char(char c, t_cmd_line *line);
void			ft_refresh_line(t_cmd_line *line);
void			ft_copy(t_cmd_line *line);
void			ft_cut(t_cmd_line *line);
void			ft_paste(t_cmd_line *line);
void			ft_init_clipboard(t_cmd_line *line);
char			*ft_clipboard(char *str);
void			ft_sel_mode_key(char key[4], t_cmd_line *line);
void			ft_sel_right(t_cmd_line *line);
void			ft_sel_left(t_cmd_line *line);
void			ft_sel_home(t_cmd_line *line);
void			ft_sel_end(t_cmd_line *line);
void			ft_sel_cancel(t_cmd_line *line);
void			ft_init_signal(void);
void			ft_restaure_signal(void);
int				ft_check_quote(t_cmd_line *line);
int				ft_miss_quote(t_cmd_line *line, char quote_type);
void			ft_completion(t_cmd_line *line);

#endif
