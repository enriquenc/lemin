/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:47:55 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/07 16:48:01 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_nbr(t_flist *lformat, uintmax_t nbr, char *str)
{
	int		result;

	result = 0;
	if (lformat->precision == 0 && nbr == 0)
		return (result);
	result += print_smth('0', lformat->precision - len_int(nbr));
	lformat->precision = 0;
	result += write(1, str, ft_strlen(str));
	free(str);
	return (result);
}

void		print_u(t_flist *lformat, uintmax_t nbr, int *result)
{
	char	*str;

	str = itoa_base(nbr, 10, 'a');
	if (lformat->flags->minus)
		(*result) += print_nbr(lformat, nbr, str);
	if ((int)ft_strlen(str) > lformat->precision)
	{
		if (lformat->flags->zero)
			(*result) += print_smth('0', lformat->width - (int)ft_strlen(str));
		else
			(*result) += print_smth(' ', lformat->width - (int)ft_strlen(str));
	}
	else
	{
		if (lformat->flags->zero)
			(*result) += print_smth('0', lformat->width - lformat->precision);
		else
			(*result) += print_smth(' ', lformat->width - lformat->precision);
		(*result) += print_smth('0', lformat->precision - (int)ft_strlen(str));
		lformat->precision = 0;
	}
	if (!(lformat->flags->minus))
		(*result) += print_nbr(lformat, nbr, str);
}
