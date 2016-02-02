/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 19:38:26 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 17:36:16 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define ERR_MALLOC "Malloc error."
# define ERR_GNL "Read error in standard input."
# define ERR_OPENDIR "Opendir error."
# define ERR_FORK "Fork error."
# define ERR_PIPE "Pipe error."
# define ERR_UNDEF "Undefined error."
# define ERR_STAT "Call system error : stat."
# define ERR_FILE_NOT_EXISTS "File does not exists."
# define ERR_FILE_IS_DIR "File is a directory."
# define ERR_FILE_NO_ACCESS "You have not permission to access this file."
# define ERR_TERM_NOT_FOUND "Environment variable TERM not found"
# define ERR_TERM_INIT "Error : can't initialize term."

typedef enum	e_file_error
{
	UNDEF,
	NOTEXIST,
	NOTDIR,
	NOTACCESS,
	ISDIR
}				t_file_error;

int			ft_syn_error(int token_type);
void		ft_error(char *error);
void		ft_put_error(int error, char *str);
void		ft_puterror(char *mes, char *param);
void		ft_file_error(int error, char *str);

#endif
