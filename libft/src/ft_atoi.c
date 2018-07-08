/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 12:23:37 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 12:23:39 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	result(long int res, int minus)
{
	if (res < 0)
	{
		if (minus)
			return (0);
		else
			return (-1);
	}
	if (minus)
		return (-res);
	return (res);
}

int			ft_atoi(const char *str)
{
	int			minus;
	long int	res;

	minus = 0;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		minus = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && res >= 0)
	{
		res *= 10;
		res += *str - 48;
		str++;
	}
	return (result(res, minus));
}
