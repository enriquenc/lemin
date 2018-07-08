/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 05:55:09 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/07/08 05:55:10 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

void push_back(t_room **rooms, char *line, int  id)
{
	t_room *r;

	r = (t_room *)malloc(sizeof(t_room));
	r->name = ft_itoa(line);
	r->id = id;
	if (rooms == NULL)
		*top = r;
	else
	{
		
	}
}

void check_hash(char *line)
{

}

void check_line(char *line, rooms)
{
	if (line[0] == '#')
	{
		check_hash(rooms, line);
	}
}

int	main(void)
{
	char *line;
	t_room *rooms;

	while(get_next_line(0, &line) > 0)
	{
		check_line(line, rooms);
	}
	return (0);
}
