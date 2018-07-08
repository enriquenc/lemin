/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:24:03 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/15 16:24:05 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_nbr(t_flist *lformat,
	uintmax_t nbr, char *str, int *result)
{
	if (lformat->precision == 0 && nbr == 0 && lformat->width)
	{
		(*result) += write(1, " ", 1);
		return ;
	}
	else if (lformat->precision == 0
		&& nbr == 0 && lformat->width == 0 && !lformat->flags->hash)
		return ;
	if (lformat->flags->minus)
		lformat->flags->zero = 0;
	if (lformat->flags->hash)
	{
		if (lformat->conversion == 'x')
			(*result) += write(1, "0x", 2);
		else
			(*result) += write(1, "0X", 2);
		lformat->flags->hash = 0;
	}
	if (!lformat->precision && !nbr)
		return ;
	(*result) += print_smth('0', lformat->precision - len_int(nbr));
	lformat->precision = 0;
	(*result) += write(1, str, ft_strlen(str));
	free(str);
}

static char		*get_nbr(t_flist *lformat,
	uintmax_t nbr, int *result, int *sign)
{
	char		*str;

	*sign = 0;
	*result = 0;
	if (lformat->conversion == 'x')
		str = itoa_base(nbr, 16, 'a');
	else
		str = itoa_base(nbr, 16, 'A');
	if (lformat->flags->hash && nbr == 0)
		lformat->flags->hash = 0;
	if (lformat->flags->hash)
		*sign = 2;
	if (lformat->flags->zero)
		if (lformat->flags->hash)
		{
			if (lformat->conversion == 'x')
				(*result) += write(1, "0x", 2);
			else
				(*result) += write(1, "0X", 2);
			lformat->flags->hash = 0;
		}
	return (str);
}

static void		print_x_opt(t_flist *lformat, int sign, int *result, char *str)
{
	(*result) += print_smth((lformat->flags->zero ? '0' : ' '), lformat->width
		- lformat->precision - sign);
	if (lformat->flags->hash)
	{
		if (lformat->conversion == 'x')
			(*result) += write(1, "0x", 2);
		else
			(*result) += write(1, "0X", 2);
		lformat->flags->hash = 0;
	}
	(*result) += print_smth('0', lformat->precision
		- (int)ft_strlen(str));
	lformat->precision = 0;
}

void			print_x(t_flist *lformat, uintmax_t nbr, int *result)
{
	int			sign;
	char		*str;

	str = get_nbr(lformat, nbr, result, &sign);
	if (lformat->flags->minus)
		print_nbr(lformat, nbr, str, result);
	if ((int)ft_strlen(str) > lformat->precision)
	{
		if (lformat->flags->zero)
			(*result) += print_smth('0', lformat->width
			- (int)ft_strlen(str) - sign);
		else
		{
			if (!lformat->flags->minus)
				(*result) += print_smth(' ', lformat->width
				- (int)ft_strlen(str) - sign);
			else
				(*result) += print_smth(' ', lformat->width - (*result));
		}
	}
	else
		print_x_opt(lformat, sign, result, str);
	if (!(lformat->flags->minus))
		print_nbr(lformat, nbr, str, result);
}
