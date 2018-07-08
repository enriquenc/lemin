/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:57:35 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/24 20:57:36 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_sign(t_flist *lformat, ssize_t nbr, t_sign *sign)
{
	int			result;

	result = 0;
	sign->is_printed = 0;
	if (nbr < 0)
		result++;
	else if (lformat->flags->space && !(lformat->flags->plus) && nbr >= 0)
	{
		result += write(1, " ", 1);
		sign->is_printed = 1;
	}
	else if (lformat->flags->plus)
		result++;
	sign->is_sign = result;
	if (sign->is_printed)
		return (1);
	else
		return (0);
}

static int		print_sign(t_flist *lformat, ssize_t *nbr, t_sign *sign)
{
	int			result;

	result = 0;
	if (*nbr < 0)
	{
		result += write(1, "-", 1);
		*nbr *= -1;
		sign->is_printed = 1;
	}
	else if (lformat->flags->plus && *nbr >= 0 && !sign->is_printed)
	{
		result += write(1, "+", 1);
		sign->is_printed = 1;
	}
	return (result);
}

static int		print_nbr(t_flist *lformat, intmax_t *nbr, t_sign *sign)
{
	char		*str;
	int			result;

	result = 0;
	if (lformat->precision == 0 && *nbr == 0 && lformat->width)
	{
		result += write(1, " ", 1);
		return (result);
	}
	else if (lformat->precision == 0 && *nbr == 0 && lformat->width == 0)
		return (result);
	result += print_sign(lformat, nbr, sign);
	str = ft_itoa(*nbr);
	lformat->flags->zero = 0;
	result += print_smth('0', lformat->precision - len_int(*nbr));
	if ((lformat->precision - len_int(*nbr)) > 0)
		lformat->width = lformat->width - (lformat->precision - len_int(*nbr));
	lformat->precision = 0;
	result += write(1, str, ft_strlen(str));
	free(str);
	return (result);
}

static int		print_flags(t_flist *lformat, intmax_t *nbr, t_sign *sign)
{
	int			result;

	result = 0;
	if (len_int(*nbr) > lformat->precision)
	{
		if (lformat->flags->zero)
			result += print_smth('0', lformat->width
			- len_int(*nbr) - sign->is_sign);
		else
			result += print_smth(' ', lformat->width
			- len_int(*nbr) - sign->is_sign);
	}
	else
	{
		if (lformat->flags->zero)
			result += print_smth('0', lformat->width
			- lformat->precision - sign->is_sign);
		else
			result += print_smth(' ', lformat->width
			- lformat->precision - sign->is_sign);
		result += print_sign(lformat, nbr, sign);
		result += print_smth('0', lformat->precision - len_int(*nbr));
		lformat->precision = -1;
	}
	return (result);
}

int				print_d(t_flist *lformat, va_list *list)
{
	intmax_t	nbr;
	int			result;
	int			i;
	t_sign		*sign;

	if (lformat->precision >= 0)
		lformat->flags->zero = 0;
	sign = (t_sign *)malloc(sizeof(t_sign));
	nbr = get_dnbr(lformat, list);
	result = 0;
	result += check_sign(lformat, nbr, sign);
	i = 0;
	if (lformat->flags->zero)
		result += print_sign(lformat, &nbr, sign);
	if (lformat->flags->minus)
		result += print_nbr(lformat, &nbr, sign);
	result += print_flags(lformat, &nbr, sign);
	if (!(lformat->flags->minus))
		result += print_nbr(lformat, &nbr, sign);
	free(sign);
	return (result);
}
