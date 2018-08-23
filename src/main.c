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

/*
** Выделение памяти на матрицу смежности
*/

void	give_memory(t_room **back, t_lem *lemin)
{
	int i;
	int j;

	j = 0;
	i = 0;
	lemin->adj_matrix = (int **)malloc(sizeof(int *) * ((*back)->id + 1));
	while (i <= (*back)->id)
	{
		lemin->adj_matrix[i] = (int *)malloc(sizeof(int) * ((*back)->id + 1));
		j = 0;
		while (j <= (*back)->id)
		{
			lemin->adj_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

/*
**Преобразование списка комнат в масив для удобства
*/

void	list_to_array(t_lem *lemin, t_room *start, t_room *back)
{
	t_room	*rooms;
	int		i;

	rooms = (t_room *)malloc(sizeof(t_room) * (back->id + 1));
	i = 0;
	while (i <= back->id)
	{
		rooms[i].id = start->id;
		rooms[i].length = start->length;
		rooms[i].name = start->name;
		rooms[i].is_path = 0;
		start = start->next;
		i++;
	}
	lemin->l = back->id + 1;
	ft_printf("\n");
	algorithm(lemin, rooms);
}

/*
**Проверка строк при парсинге
*/

int		check_line(char *line, t_room **back, t_lem *lemin, t_room *start)
{
	if (line[0] == '#')
		check_hash(line, lemin, back);
	else if (line[0] == 'L')
		error("Room starts from 'L' can't exist.");
	else if (lemin->number_of_ants == -1)
		check_ants(line, lemin);
	else if (ft_strchr(line, ' '))
		check_room(line, back, start);
	else
		return (check_link(line, lemin, back, start));
	return (0);
}

int		main(void)
{
	char	*line;
	t_room	*start;
	t_room	*back;
	t_lem	*lemin;

	start = (t_room *)malloc(sizeof(t_room));
	start->name = NULL;
	start->id = -1;
	back = start;
	lemin = (t_lem *)malloc(sizeof(t_room));
	lemin->start = -1;
	lemin->end = -1;
	lemin->number_of_ants = -1;
	lemin->adj_matrix = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (check_line(line, &back, lemin, start))
			break ;
		ft_printf("%s\n", line);
		free(line);
	}
	list_to_array(lemin, start, back);
	system("leaks lem-in");
	return (0);
}
