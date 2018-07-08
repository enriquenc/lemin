/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:16:28 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/04/12 19:59:27 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42
# include "libft.h"

typedef struct		s_bufer
{
	int				fd;
	char			*buf;
	struct s_bufer	*next;
}					t_bufer;

int					get_next_line(const int fd, char **line);

#endif
