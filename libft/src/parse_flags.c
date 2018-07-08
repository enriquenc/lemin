/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:13:00 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/11 15:13:04 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(const char **format, t_flist *lformat, va_list *list)
{
	if (ft_isdigit(**format))
	{
		lformat->width = ft_atoi(*format);
		(*format) += len_int(lformat->width);
	}
	if (**format == '*')
	{
		lformat->width = va_arg(*list, int);
		if (lformat->width < 0)
		{
			lformat->width *= -1;
			lformat->flags->minus = 1;
		}
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		lformat->width = ft_atoi(*format);
		(*format) += len_int(lformat->width);
	}
}

void	parse_precision(const char **format, t_flist *lformat, va_list *list)
{
	if (**format == '.')
	{
		lformat->precision = 0;
		(*format)++;
	}
	if (**format == '*')
	{
		lformat->precision = va_arg(*list, int);
		(*format)++;
		return ;
	}
	if (ft_isdigit(**format))
	{
		lformat->precision = ft_atoi(*format);
		(*format) += len_int(lformat->precision);
	}
}

void	parse_size(const char **format, t_flist *lformat)
{
	if (**format == 'h' && *((*format) + 1) == 'h')
	{
		lformat->size = "hh";
		(*format) += 2;
		return ;
	}
	else if (**format == 'l' && *((*format) + 1) == 'l')
	{
		lformat->size = "ll";
		(*format) += 2;
		return ;
	}
	else if (**format == 'h')
		lformat->size = "h";
	else if (**format == 'l')
		lformat->size = "l";
	else if (**format == 'j')
		lformat->size = "j";
	else if (**format == 'z')
		lformat->size = "z";
	else
		return ;
	(*format)++;
}

void	parse_conversion(const char **format, t_flist *lformat, int *result)
{
	if (**format == 'i' || **format == 'd' || **format == 'D')
		lformat->conversion = 'd';
	else if (**format == 's' || **format == 'S')
		lformat->conversion = 's';
	else if (**format == 'o' || **format == 'O')
		lformat->conversion = 'o';
	else if (**format == 'u' || **format == 'U')
		lformat->conversion = 'u';
	else if (**format == 'x')
		lformat->conversion = 'x';
	else if (**format == 'X')
		lformat->conversion = 'X';
	else if (**format == 'p')
		lformat->conversion = 'p';
	else if (**format == 'c' || **format == 'C')
		lformat->conversion = 'c';
	else if (**format == '%')
		lformat->conversion = '%';
	else
		undefined_parse(result, lformat, **format);
	if (**format == 'O' || **format == 'S' ||
	**format == 'D' || **format == 'U' || **format == 'C')
		lformat->size = "l";
	(*format)++;
}

void	parse_flags(const char **format, t_flist *lformat)
{
	while (**format == '-' || **format == '+' || **format == ' ' ||
		**format == '0' || **format == '#')
	{
		if (**format == ' ')
			lformat->flags->space = 1;
		else if (**format == '+')
			lformat->flags->plus = 1;
		else if (**format == '-')
			lformat->flags->minus = 1;
		else if (**format == '0')
			lformat->flags->zero = 1;
		else if (**format == '#')
			lformat->flags->hash = 1;
		(*format)++;
		if (**format == ' ')
			lformat->flags->space = 1;
		pass_spaces(format);
	}
}
