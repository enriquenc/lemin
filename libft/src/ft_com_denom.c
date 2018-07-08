/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_com_denom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:41:10 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/28 19:41:11 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_com_denom(int x, int y)
{
	int denom;

	if (x <= 0 || y <= 0)
		return (0);
	if (x > y)
		denom = y;
	else
		denom = x;
	while (denom)
	{
		if (!(x % denom) && !(y % denom))
			return (denom);
		--denom;
	}
	return (denom);
}
