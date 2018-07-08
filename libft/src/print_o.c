/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:21:30 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/07 17:21:31 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_nbr(t_flist *lformat,
	uintmax_t nbr, char *str, int *result)
{
	if (lformat->precision == -1 && nbr == 0)
		lformat->flags->hash = 0;
	if (lformat->precision == 0 && nbr == 0 && lformat->width)
	{
		(*result) += write(1, " ", 1);
		return ;
	}
	else if (lformat->precision == 0 && nbr == 0
	&& lformat->width == 0 && !lformat->flags)
		return ;
	if (lformat->flags->minus)
		lformat->flags->zero = 0;
	if (lformat->flags->hash)
	{
		(*result) += write(1, "0", 1);
		lformat->flags->hash = 0;
	}
	if (!lformat->precision && !nbr)
		return ;
	(*result) += print_smth('0', lformat->precision - len_int(nbr));
	lformat->precision = 0;
	(*result) += write(1, str, ft_strlen(str));
}

static void		optimz2(t_flist *lformat, char *str, int *result, int sign)
{
	if (lformat->flags->zero)
		(*result) += print_smth('0', lformat->width
		- lformat->precision - sign);
	else
		(*result) += print_smth(' ', lformat->width
		- lformat->precision - sign);
	if (lformat->flags->hash)
	{
		(*result) += write(1, "0", 1);
		lformat->flags->hash = 0;
	}
	(*result) += print_smth('0', lformat->precision
	- (int)ft_strlen(str) - sign);
	lformat->precision = 0;
}

static void		optimz(t_flist *lformat, char *str, int *result, int sign)
{
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
		optimz2(lformat, str, result, sign);
}

int				print_o(t_flist *lformat, uintmax_t nbr)
{
	int			result;
	int			sign;
	char		*str;

	sign = 0;
	result = 0;
	str = itoa_base(nbr, 8, 'a');
	if (lformat->flags->hash)
		sign = 1;
	if (lformat->flags->zero)
		if (lformat->flags->hash)
		{
			result += write(1, "0", 1);
			lformat->flags->hash = 0;
		}
	if (lformat->flags->minus)
		print_nbr(lformat, nbr, str, &result);
	optimz(lformat, str, &result, sign);
	if (!(lformat->flags->minus))
		print_nbr(lformat, nbr, str, &result);
	free(str);
	return (result);
}
