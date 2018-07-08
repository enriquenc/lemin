/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:22:46 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/16 16:22:47 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*get_str(t_flist *lformat, va_list *list)
{
	wchar_t *result;

	if (lformat->size)
		result = va_arg(*list, wchar_t *);
	else
		result = (wchar_t *)va_arg(*list, char *);
	return (result);
}

void		write_str(char *s, t_flist *lformat, int *result)
{
	char	*str;
	int		print;

	print = 1;
	str = NULL;
	if (lformat->precision == 0)
		print = 0;
	if (s == NULL)
		str = ft_strdup("(null)");
	else if (lformat->precision)
	{
		str = ft_strdup(s);
		(lformat->precision > 0 && lformat->precision < (int)ft_strlen(str))
		? (str[lformat->precision] = 0)
		: (lformat->precision = ft_strlen(str));
	}
	if (lformat->flags->minus && print)
		(*result) += write(1, str, ft_strlen(str));
	(*result) += print_smth((lformat->flags->zero ? '0' : ' ')
	, lformat->width - lformat->precision - (lformat->precision == -1
	? ft_strlen(str) + 1 : 0));
	if (!lformat->flags->minus && print)
		(*result) += write(1, str, ft_strlen(str));
	free(str);
}

int			check_size(wchar_t *str)
{
	int result;

	result = 0;
	while (*str)
	{
		result += check_bytes(*str);
		str++;
	}
	return (result);
}

int			print_s(t_flist *lformat, va_list *list, int *result)
{
	wchar_t	*str;
	int		size;

	size = 0;
	str = get_str(lformat, list);
	if (!lformat->size || str == NULL)
	{
		write_str((char *)str, lformat, result);
		return (0);
	}
	else
	{
		size = lformat->precision > 0 ? lformat->precision : check_size(str);
		if (*str >= 256 && MB_CUR_MAX == 1)
			return (-1);
		while (lformat->flags->minus && *str && lformat->precision)
			(*result) += check_mask(*str++);
		(*result) += print_smth((lformat->flags->zero ? '0'
		: ' '), lformat->width - (lformat->precision ? size : 0));
		while (!lformat->flags->minus && *str && lformat->precision)
			(*result) += check_mask(*str++);
	}
	return (0);
}
