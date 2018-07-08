/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:28:08 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 15:28:09 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	size;
	size_t	begin;
	size_t	end;
	char	*res;

	if (s == NULL)
		return (NULL);
	begin = 0;
	while (s[begin] == '\n' || s[begin] == ' ' || s[begin] == '\t')
		begin++;
	if (s[begin] == '\0')
		return (ft_strdup(""));
	size = ft_strlen(s);
	end = 0;
	while (s[size - end - 1] == '\n' ||
		s[size - end - 1] == ' ' || s[size - end - 1] == '\t')
		end++;
	if (begin == 0 && end == 0)
		return (ft_strdup(s));
	res = (char *)malloc(sizeof(*res) * (size - (end + begin) + 1));
	if ((res) == NULL)
		return (NULL);
	res = ft_strsub(s, begin, size - (end + begin));
	return (res);
}
