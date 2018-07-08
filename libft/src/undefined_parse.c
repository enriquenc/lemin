/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:01:04 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/18 16:01:05 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	undefined_parse(int *result, t_flist *lformat, char c)
{
	if (lformat->flags->minus)
		*result += write(1, &c, 1);
	*result += print_smth((lformat->flags->zero ? '0' : ' ')
	, lformat->width - 1);
	if (!lformat->flags->minus)
		*result += write(1, &c, 1);
}

int		check_bytes(wchar_t chr)
{
	int bytes;

	bytes = 0;
	if (chr < 128 || (MB_CUR_MAX == 1 && chr < 256))
		bytes = 1;
	else if (chr < 2048)
		bytes = 2;
	else if (chr < 65536)
		bytes = 3;
	else
		bytes = 4;
	return (bytes);
}
