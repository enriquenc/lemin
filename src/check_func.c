/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:18:32 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/08/23 12:18:33 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

/*
** Функция для работы с хешами
*/

void	check_hash(char *line, t_lem *lemin, t_room **back)
{
	if (lemin->number_of_ants > 0)
	{
		if (ft_strequ(line + 1, "#start") && lemin->start != -1)
			error("Error command ##start. Start room is already exist.");
		if (ft_strequ(line + 1, "#end") && lemin->end != -2)
			error("Error command ##end. End room is already exist.");
		if (ft_strequ(line + 1, "#start") && lemin->start == -1)
			lemin->start = (*back)->id + 1;
		else if (ft_strequ(line + 1, "#end") && lemin->end == -2)
			lemin->end = (*back)->id + 1;
	}
	if (lemin->start == lemin->end)
		error("Bad farm.");
}

/*
** Проверка на валидность количества муравьев.
*/

void	check_ants(char **line, t_lem *lemin)
{
	int i;

	i = 0;
	while ((*line)[i])
	{
		if (!ft_isdigit((*line)[i]))
			error("Bad number of ants.");
		i++;
	}
	lemin->number_of_ants = ft_atoi(*line);
	if (lemin->number_of_ants < 0 || lemin->number_of_ants > 2147483647)
		error("Number of ants is not positive integer.");
	if (lemin->number_of_ants == 0)
		error("There is no ant.");
}

/*
** Добавление комнаты в список
** Проверка координат на валидность (проверка  на int)
*/

void	check_room(char *line, t_room **back, t_room *start)
{
	char	**room;
	int		i;

	i = 0;
	check_spaces(line);
	room = ft_strsplit(line, ' ');
	while (room[i++])
		;
	if (i != 4)
		error("Bad name of the room.");
	i = 0;
	while (room[0][i])
	{
		if (room[0][i] == '-')
			error("Bad name of the room. Room can't consist of \'-\' symbols.");
		i++;
	}
	check_coords(room);
	if (find_id(room[0], back, start) != (*back)->id + 1)
		error("You can't use the same name of the room.");
	push_back(back, room[0]);
	free_it(room);
}

/*
** Проверка на то ли существует нужный путь
*/

void	valid_check(t_lem *lemin)
{
	int i;
	int j;

	i = 0;
	if (lemin->l == 0)
		error("There is no valid rooms.");
	if (lemin->start == -1 || lemin->end == -2)
		error("There is no ##start / ##end.");
	if (lemin->adj_matrix == NULL)
		error("Invalid ant-farm. There is no possible solution.");
	while (i < lemin->l)
	{
		if (lemin->adj_matrix[lemin->start][i] != 0)
			break ;
		i++;
	}
	j = 0;
	while (j < lemin->l)
	{
		if (lemin->adj_matrix[lemin->end][j] != 0)
			break ;
		j++;
	}
	if (i == lemin->l || j == lemin->l)
		error("Invalid ant-farm. There is no possible solution.");
}

/*
** Парсинг линков и формирование матрицы смежности
*/

int		check_link(char *line, t_lem *lemin, t_room **back, t_room *start)
{
	char	**link;
	int		i;
	int		j;

	if (check_sub(line, lemin, back) || !(link = check_link_opt(line)))
		return (1);
	if (lemin->adj_matrix == NULL)
		give_memory(back, lemin);
	i = find_id(link[0], back, start);
	j = find_id(link[1], back, start);
	if (i == (*back)->id + 1 || j == (*back)->id + 1)
	{
		free_it(link);
		return (1);
	}
	if (i == j)
	{
		free_it(link);
		return (0);
	}
	lemin->adj_matrix[i][j] = 1;
	lemin->adj_matrix[j][i] = 1;
	free_it(link);
	return (0);
}
