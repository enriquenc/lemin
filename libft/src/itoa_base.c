/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:27:52 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/19 23:45:46 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*itoa_base(uintmax_t nbr, int base, char size)
{
	uintmax_t	temp;
	int			i;
	char		*res;

	temp = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	i = 1;
	if (base < 2 || base > 16)
		return (NULL);
	while ((temp /= base))
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i--] = '\0';
	while (nbr)
	{
		if ((nbr % base + 48) <= 57)
			res[i--] = nbr % base + 48;
		else
			res[i--] = nbr % base + (size == 'A' ? 55 : 87);
		nbr = nbr / base;
	}
	return (res);
}
