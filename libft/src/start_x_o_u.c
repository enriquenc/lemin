/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_x_o_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 13:03:35 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/01 13:03:56 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_unbr(t_flist *lformat, va_list *list)
{
	uintmax_t	nbr;

	nbr = 0;
	if (lformat->size)
	{
		if (lformat->size[0] == 'h' && lformat->size[1] == 'h')
			nbr = (unsigned char)va_arg(*list, unsigned int);
		else if (lformat->size[0] == 'h' && lformat->size[1] == '\0')
			nbr = (unsigned short)va_arg(*list, unsigned int);
		else if (lformat->size[0] == 'l' && lformat->size[1] == '\0')
			nbr = va_arg(*list, unsigned long);
		else if (lformat->size[0] == 'l' && lformat->size[1] == 'l')
			nbr = va_arg(*list, unsigned long long);
		else if (lformat->size[0] == 'j' && lformat->size[1] == '\0')
			nbr = va_arg(*list, intmax_t);
		else if (lformat->size[0] == 'z' && lformat->size[1] == '\0')
			nbr = va_arg(*list, size_t);
	}
	else
		nbr = va_arg(*list, unsigned int);
	return (nbr);
}

int				start_x_o_u(t_flist *lformat, va_list *list)
{
	int			result;
	uintmax_t	nbr;

	nbr = get_unbr(lformat, list);
	result = 0;
	if (lformat->conversion == 'u')
		print_u(lformat, nbr, &result);
	else if (lformat->conversion == 'o')
		result += print_o(lformat, nbr);
	else if (lformat->conversion == 'x' || lformat->conversion == 'X')
		print_x(lformat, nbr, &result);
	return (result);
}
