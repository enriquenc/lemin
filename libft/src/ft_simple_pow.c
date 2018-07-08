/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:33:53 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/26 14:33:55 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_simple_pow(int nbr, int power)
{
	int res;

	res = nbr;
	if (nbr == 0)
		return (0);
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		res = res * nbr;
		power--;
	}
	if (nbr > 0 && res < 0)
		return (0);
	return (res);
}
