/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:44:47 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/26 11:45:28 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intsqrt(size_t nbr)
{
	size_t sqrt;

	sqrt = 0;
	if (nbr == 0)
		return (0);
	if (nbr == 1)
		return (1);
	while (sqrt <= nbr / 2)
	{
		if (sqrt * sqrt == nbr)
			return (sqrt);
		sqrt++;
	}
	return (0);
}
