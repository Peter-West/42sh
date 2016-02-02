/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 16:25:11 by rfrey             #+#    #+#             */
/*   Updated: 2014/03/26 17:59:03 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# define TYPE_ERROR 0
# define CHAR 1
# define STRING 2
# define INT 3
# define DOUBLE 4
# define ATTR "#0' +-"
# define NBR "0123456789"
# define ATTRNBR 12
# define ATTR_SHARP 0
# define ATTR_ZERO 1
# define ATTR_DASH 2
# define ATTR_PLUS 3
# define ATTR_APOST 4
# define ATTR_SPACE 5
# define ATTR_WIDTH 6
# define ATTR_HAVEPREC 7
# define ATTR_PRECVALUE 8
# define ATTR_TYPE 9
# define ATTR_SUBTYPE 10
# define ATTR_ISNEG 11

int			ft_printf(const char *str, ...);
int			ft_parse(int *cnt, char **start, const char **str, int **format);
int			ft_get_format(const char **str, int *format);
int			ft_get_type(const char *end, int *format);
void		ft_fchar(char c, int *cnt, int *format);
void		ft_fstring(char *str, int *cnt, int *format);
void		ft_fint(int n, int *cnt, int *format);
void		ft_fdouble(double d, int *cnt, int *format);
int			ft_is_int(char c);
int			ft_is_float(char c);
const char	*ft_skip(const char *str, char *skipchr);
void		ft_fill_field(int n, int *format);
void		ft_putfield(char *str, int *format, int *cnt);
int			*ft_init_format(void);
void		ft_getattr(const char **str, int *format);
char		*ft_itobase(unsigned int n, unsigned int b);
char		*ft_toupperstr(char *str);
int			ft_putsign(int *f);
char		*ft_fill_zero(char *str, int *format);
void		ft_putsignedstr(char *str, int *format);
char		*ft_generate_int_str(int n, int *format);
char		*ft_addoctalprefix(char **str);
char		*ft_addhexaprefix(char **str);
void		ft_convert(va_list ap, int *cnt, int *format);

#endif
