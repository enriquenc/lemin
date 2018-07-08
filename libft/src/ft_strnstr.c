/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 10:59:15 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 10:59:17 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_iter(const char **haystack, size_t *i)
{
	(*haystack)++;
	(*i)++;
}

static void	str_restart(const char **haystack,
			char **haystack_temp, const char **needle, char **temp)
{
	(*needle) = (*temp);
	(*haystack) = (*haystack_temp);
}

static void	check_for_needle(const char **haystack,
			const char **needle, size_t *i, size_t len)
{
	while (**needle && *i < len)
	{
		if (**haystack != **needle)
			break ;
		(*haystack)++;
		(*needle)++;
		(*i)++;
	}
}

static void	ft_temp(size_t *temp_i, char **haystack_temp,
			size_t i, const char *haystack)
{
	(*temp_i) = i;
	(*haystack_temp) = (char *)haystack;
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*temp;
	char	*haystack_temp;
	size_t	i;
	size_t	temp_i;

	i = 0;
	temp = (char *)needle;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && i < len)
	{
		if (*haystack == *needle)
		{
			ft_temp(&temp_i, &haystack_temp, i, haystack);
			check_for_needle(&haystack, &needle, &i, len);
			if (!*needle)
				return (haystack_temp);
			str_restart(&haystack, &haystack_temp, &needle, &temp);
			i = temp_i;
		}
		str_iter(&haystack, &i);
	}
	return (NULL);
}
