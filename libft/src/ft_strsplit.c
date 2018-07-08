/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:18:22 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/22 14:27:28 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_words(const char *str, char c)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		res++;
		while (str[i] && str[i] != c)
			i++;
		if (str[i] && str[i] == c)
			while (str[i] && str[i] == c)
				i++;
	}
	return (res);
}

static int	ft_check_letters(const char **str, char c)
{
	int res;

	res = 0;
	while (**str && **str == c)
		(*str)++;
	while (**str && **str != c)
	{
		(*str)++;
		res++;
	}
	return (res);
}

static int	give_memory(char ***result, const char *str, char c)
{
	const char	*temp;
	int			i;

	temp = str;
	if (str == NULL)
		return (-1);
	if ((*result = (char **)malloc(sizeof(char *)
	* (ft_check_words(str, c) + 1))) == NULL)
		return (-1);
	i = -1;
	str = temp;
	while (++i < ft_check_words(temp, c))
		if (((*result)[i] = (char *)malloc(sizeof(char)
		* (ft_check_letters(&str, c) + 1))) == NULL)
		{
			while (i > 0)
				free((*result)[--i]);
			free(*result);
			return (-1);
		}
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	char	*temp;

	if (give_memory(&result, s, c))
		return (NULL);
	i = 0;
	temp = (char *)s;
	while (i < ft_check_words(temp, c))
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		while (*s && *s != c)
			result[i][j++] = *s++;
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}
