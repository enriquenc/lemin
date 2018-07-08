/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:49:34 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/26 11:49:35 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nextprime(size_t nbr)
{
	if (nbr == 0)
		return (2);
	if (nbr == 1)
		return (2);
	while (1)
	{
		nbr++;
		if (ft_isprime(nbr))
			return (nbr);
	}
}
