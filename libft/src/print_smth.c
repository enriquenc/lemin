/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_smth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:43:23 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/07 16:43:24 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_smth(char to_print, int length)
{
	int	result;

	if (length <= 0)
		return (0);
	result = 0;
	while (length--)
		result += write(1, &to_print, 1);
	return (result);
}
