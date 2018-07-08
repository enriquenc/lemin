/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:47:42 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/17 18:47:43 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_dnbr(t_flist *lformat, va_list *list)
{
	intmax_t nbr;

	nbr = 0;
	if (lformat->size)
	{
		if (lformat->size[0] == 'h' && lformat->size[1] == 'h')
			nbr = (signed char)va_arg(*list, int);
		else if (lformat->size[0] == 'h' && lformat->size[1] == '\0')
			nbr = (short)va_arg(*list, int);
		else if (lformat->size[0] == 'l' && lformat->size[1] == '\0')
			nbr = va_arg(*list, long int);
		else if (lformat->size[0] == 'l' && lformat->size[1] == 'l')
			nbr = va_arg(*list, long long int);
		else if (lformat->size[0] == 'j' && lformat->size[1] == '\0')
			nbr = va_arg(*list, intmax_t);
		else if (lformat->size[0] == 'z' && lformat->size[1] == '\0')
			nbr = va_arg(*list, ssize_t);
	}
	else
		nbr = va_arg(*list, int);
	return (nbr);
}
