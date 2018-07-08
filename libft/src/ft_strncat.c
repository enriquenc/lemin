/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 08:24:41 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 08:24:42 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = s1;
	if (n <= 0)
		return (s1);
	while (*temp)
		temp++;
	while (*s2 && i < n)
	{
		*temp++ = *s2++;
		i++;
	}
	*temp = '\0';
	return (s1);
}
