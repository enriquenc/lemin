/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:20:49 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/17 15:53:45 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_init(t_flist **lformat)
{
	(*lformat)->flags->minus = 0;
	(*lformat)->flags->zero = 0;
	(*lformat)->flags->plus = 0;
	(*lformat)->flags->space = 0;
	(*lformat)->flags->hash = 0;
	(*lformat)->width = 0;
	(*lformat)->precision = -1;
	(*lformat)->size = NULL;
	(*lformat)->conversion = 0;
}

int			print(t_flist *lformat, va_list *list)
{
	int result;

	result = 0;
	if (lformat->conversion == '%')
		result += print_percent(lformat);
	if (lformat->conversion == 'd')
		result += print_d(lformat, list);
	else if (lformat->conversion == 'x' || lformat->conversion == 'X'
	|| lformat->conversion == 'u' || lformat->conversion == 'o')
		result += start_x_o_u(lformat, list);
	else if (lformat->conversion == 'c')
		result += print_c(lformat, list);
	else if (lformat->conversion == 's')
		result += print_s(lformat, list, &result);
	else if (lformat->conversion == 'p')
		result += print_p(lformat, list);
	return (result);
}

void		parse_start(va_list *list,
			const char *format, t_flist *lformat, int *result)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			lst_init(&lformat);
			parse_flags(&format, lformat);
			parse_width(&format, lformat, list);
			if (*format == '.')
				parse_precision(&format, lformat, list);
			parse_size(&format, lformat);
			parse_conversion(&format, lformat, result);
			(*result) += print(lformat, list);
		}
		else
		{
			(*result) += write(1, &(*format), 1);
			format++;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	int		result;
	va_list list;
	t_flist *lformat;

	result = 0;
	lformat = (t_flist *)malloc(sizeof(t_flist));
	lformat->flags = (t_flags *)malloc(sizeof(t_flist));
	if (format)
	{
		va_start(list, format);
		parse_start(&list, format, lformat, &result);
	}
	free(lformat->flags);
	free(lformat);
	return (result);
}
