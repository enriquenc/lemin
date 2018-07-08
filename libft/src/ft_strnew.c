/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:27:20 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 13:27:21 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	if ((res = (char *)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	res = (char *)ft_memset(res, '\0', size + 1);
	return (res);
}
