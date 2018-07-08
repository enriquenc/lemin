/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:21:14 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/15 18:21:15 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percent(t_flist *lformat)
{
	int	result;

	result = 0;
	if (lformat->flags->minus)
	{
		lformat->flags->zero = 0;
		result += write(1, "%", 1);
	}
	if (lformat->flags->zero)
		result += print_smth('0', lformat->width - 1);
	else
		result += print_smth(' ', lformat->width - 1);
	if (!lformat->flags->minus)
		result += write(1, "%", 1);
	return (result);
}
