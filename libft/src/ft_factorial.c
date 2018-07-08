/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:45:43 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/26 11:45:45 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_factorial(int nbr)
{
	size_t res;

	if (nbr > 20 || nbr < 0)
		return (0);
	if (nbr == 0)
		return (1);
	res = 1;
	while (nbr > 1)
	{
		res = res * nbr;
		nbr--;
	}
	return (res);
}
