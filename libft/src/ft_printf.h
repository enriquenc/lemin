/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:21:05 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/16 15:21:07 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			plus;
	int			space;
	int			hash;
}				t_flags;

typedef struct	s_flist
{
	t_flags		*flags;
	int			width;
	int			precision;
	char		*size;
	char		conversion;
}				t_flist;

typedef struct	s_sign
{
	int			is_sign;
	int			sign;
	int			is_printed;
}				t_sign;

int				ft_printf(const char *format, ...);
int				print_d(t_flist *lformat, va_list *list);
int				start_x_o_u(t_flist *lformat, va_list *list);
int				print_smth(char to_print, int length);
void			pass_spaces(const char **format);
void			parse_width(const char **format,
				t_flist *lformat, va_list *list);
void			parse_precision(const char **format,
				t_flist *lformat, va_list *list);
void			parse_size(const char **format, t_flist *lformat);
void			parse_conversion(const char **format, t_flist *lformat,
				int *result);
void			parse_flags(const char **format, t_flist *lformat);
int				print_o(t_flist *lformat, uintmax_t nbr);
void			print_u(t_flist *lformat, uintmax_t nbr, int *result);
void			print_x(t_flist *lformat, uintmax_t nbr, int *result);
int				print_percent(t_flist *lformat);
int				print_c(t_flist *lformat, va_list *list);
int				print_s(t_flist *lformat, va_list *list, int *result);
int				check_mask(wchar_t chr);
int				print_p(t_flist *lformat, va_list *list);
intmax_t		get_dnbr(t_flist *lformat, va_list *list);
void			undefined_parse(int *result, t_flist *lformat, char c);
int				check_bytes(wchar_t chr);

#endif
