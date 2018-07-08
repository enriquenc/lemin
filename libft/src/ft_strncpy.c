/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 07:05:13 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 07:05:23 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*temp;
	size_t	i;

	temp = dst;
	i = 0;
	while (*src && i < len)
	{
		*temp++ = *src++;
		i++;
	}
	while (i < len)
	{
		*temp++ = '\0';
		i++;
	}
	return (dst);
}
