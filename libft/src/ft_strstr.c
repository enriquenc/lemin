/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 09:51:54 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 09:51:56 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_iter(const char **haystack,
			const char **needle)
{
	(*haystack)++;
	(*needle)++;
}

static void	str_restart(const char **haystack,
			char **haystack_temp, const char **needle, char **temp)
{
	(*needle) = (*temp);
	(*haystack) = (*haystack_temp);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	char *temp;
	char *haystack_temp;

	temp = (char *)needle;
	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			haystack_temp = (char *)haystack;
			while (*needle)
			{
				if (*haystack != *needle)
					break ;
				str_iter(&haystack, &needle);
			}
			if (!*needle)
				return (haystack_temp);
			str_restart(&haystack, &haystack_temp, &needle, &temp);
		}
		haystack++;
	}
	return (NULL);
}
