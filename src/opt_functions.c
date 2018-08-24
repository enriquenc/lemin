/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:08:30 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/08/23 12:08:32 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

/*
** Вывод ошибок
*/

void	error(const char *message)
{
	ft_printf("\n\033[;31mERROR: \033[0m%s\n", message);
	exit(0);
}

/*
** Проверка координат на валидность
*/

void	check_coords(char **room)
{
	int i;
	int j;

	i = 1;
	while (i < 3)
	{
		j = 0;
		while (room[i][j])
		{
			if (!ft_isdigit(room[i][j]))
				error("Bad coordinates.");
			j++;
		}
		i++;
	}
	if (ft_atoi(room[1]) > 2147483647 || ft_atoi(room[1]) < 0
		|| ft_atoi(room[2]) < 0 || ft_atoi(room[2]) > 2147483647)
		error("Coordinates are not integer.");
}

/*
** Проверка на количество пробелов в объявлении комнаты
*/

void	check_spaces(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			j++;
		i++;
	}
	if (j > 2)
		error("Bad number of spaces.");
}

/*
** Поиск и сопоставление линка и имени в списке комнат.
** Возврат соответствующего id
** Проверка на валидность линка
*/

int		find_id(char *link, t_room **back, t_room *start)
{
	int i;

	i = 0;
	while (i <= (*back)->id)
	{
		if (ft_strequ(link, start->name))
			break ;
		start = start->next;
		i++;
	}
	return (i);
}

/*
** Проверка: один ли минус в линке.
*/

int		check_sub(char *line, t_lem *lemin, t_room **back)
{
	int i;
	int j;

	lemin->links = 1;
	if (lemin->start >= (*back)->id + 1 || lemin->end >= (*back)->id + 1)
		error("There is no ##start / ##end room.");
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '-')
			j++;
		i++;
	}
	if (j != 1)
		return (1);
	return (0);
}
