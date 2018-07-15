/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:54:54 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/07/08 05:54:56 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define NOT_CHECKED -1
# define ALREADY_IN_PATH -2

# include "../libft/include/libft.h"
# include <stdint.h>

typedef	struct	s_room
{
	int				id;
	int				length;
	char			*name;
	struct s_room	*next;
}				t_room;

typedef struct	s_lem
{
	int start;
	int end;
	int number_of_ants;
	int **adj_matrix;
}				t_lem;
#endif