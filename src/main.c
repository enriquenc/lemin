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
#include <stdio.h>


/*
** Вывод ошибок
*/

void error(void)
{
	ft_printf("ERROR\n");
	exit(0); 
}

/*
** Добавление комнаты в список
*/

void push_back(t_room **back, char *name)
{
	if ((*back)->name == NULL)
	{
		(*back)->name = ft_strdup(name);
		(*back)->id = 0;
		(*back)->length = NOT_CHECKED;
	}
	else
	{
		(*back)->next = (t_room *)malloc(sizeof(t_room));
		(*back)->next->length = NOT_CHECKED;
		(*back)->next->id = (*back)->id + 1;
		(*back)->next->name = ft_strdup(name);
		(*back) = (*back)->next;
		(*back)->next = NULL;
	}
}

/*
** Функия для работы с хешами
*/

void check_hash(char *line, t_lem *lemin, t_room **back)
{
	if (ft_strequ(line + 1, "#start") && lemin->start == -1)
		lemin->start = (*back)->id + 1;
	else if (ft_strequ(line + 1, "#end") && lemin->end == -1)
		lemin->end = (*back)->id + 1;
}

/*
** Проверка на валидность количества муравьев.
*/

void check_ants(char *line, t_lem *lemin)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			error();
		i++;
	}
	lemin->number_of_ants = ft_atoi(line);
	if (lemin->number_of_ants <= 0)
		error();
}

/*
** Добавление комнаты в список
** Проверка координат на валидность (еще нужно доделать проверку на int)
*/

void check_room(char *line, t_room **back)
{
	char **room;
	int i;
	int j;

	room = ft_strsplit(line, ' ');
	i = 0;
	while (room[i] != NULL)
		i++;
	if (i != 3)
		error();
	i = 1;
	while (i < 3)
	{
		j = 0;
		while (room[i][j])
		{
			if (!ft_isdigit(room[i][j])  && room[i][j] == '-')
				error();
			j++;
		}
		i++;
	}
	push_back(back, room[0]);
}


/*
** Поиск и сопоставление линка и имени в списке комнат. 
** Возврат соответствующего id
** Проверка на валидность линка
*/
int find_id(char *link, t_room **back, t_room *start)
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
	if (i == (*back)->id + 1)
		error();
	return (i);
}

/*
** Выделение памяти на матрицу смежности
*/

void give_memory(t_room **back, t_lem *lemin)
{
	int i;

	i = 0;
	lemin->adj_matrix = (int **)malloc(sizeof(int *) * ((*back)->id + 1));
	while (i <= (*back)->id)
	{
		lemin->adj_matrix[i] = (int *)malloc(sizeof(int) * ((*back)->id + 1));
		ft_bzero(lemin->adj_matrix[i], (*back)->id + 1);
		i++;
	}
}

/*
** Парсинг линков и формирование матрицы смежности
*/
void check_link(char *line, t_lem *lemin, t_room **back, t_room *start)
{
	char **link;
	int i;
	int j;

	link = ft_strsplit(line, '-');
	i = 0;
	while (link[i] != NULL)
		i++;
	if (i != 2)
		error();
	if (lemin->adj_matrix == NULL)
		give_memory(back, lemin);
	i = find_id(link[0], back, start);
	j = find_id(link[1], back, start);
	lemin->adj_matrix[i][j] = 1;
	lemin->adj_matrix[j][i] = 1;
}

/*
**Проверка строк при парсинге
*/
void check_line(char *line, t_room **back , t_lem *lemin, t_room *start)
{
	
	if (line[0] == '#')
		check_hash(line, lemin, back);
	else if (line[0] == 'L')
		error();
	else if (lemin->number_of_ants == -1)
		check_ants(line, lemin);
	else if (ft_strchr(line, ' '))
		check_room(line, back);
	else
		check_link(line, lemin, back, start);
}

/*
**Добавление комнаты в очередь, при обходе в ширину
*/
void add(t_queue *q, int i)
{
	while(q->next != NULL)
		q = q->next;
	q->next = (t_queue *)malloc(sizeof(t_queue));
	q->next->prev = q;
	q->next->next = NULL;
	q->next->number = q->number + 1;
	q->next->id = i;
}

void algotithm(t_lem *lemin, t_room *rooms)
{
	int i;
	t_queue *q;
	int temp;

	rooms[lemin->start].length = 0;
	q = (t_queue *)malloc(sizeof(t_queue));
	q->id = lemin->start;
	ft_printf("start = %d\nend = %3d\nlemin->l = %d\n", lemin->start, lemin->end, lemin->l);
	q->number = 0;
	q->prev = NULL;
	q->next = NULL;
	printf("start while\n\n");
	while(1)
	{
		i = 0;
		temp = q->id;
		while (i < lemin->l)
		{
			if (lemin->adj_matrix[temp][i] == 1 && rooms[i].length == NOT_CHECKED)
			{
				add(q, i);
				rooms[i].length = q->number + 1;
				ft_printf("%d\n", q->next->id);
			}
			i++;
		}
		if(q->next == NULL)
		{
			free(q);
			break;
		}
		q = q->next;
		free(q->prev);
		q->prev = NULL;
	}
	ft_printf("end while\n");
	int j = 0;
	while(j < lemin->l)
	{
		ft_printf("rooms[%d].length = %d\n", j, rooms[j].length);
		j++;
	}
}
/*
**Преобразование списка комнат в масив для удобства
*/
void list_to_array(t_lem *lemin, t_room *start, t_room *back)
{
	t_room *rooms;
	int i;

	rooms = (t_room *)malloc(sizeof(t_room) * (back->id + 1));
	i = 0;
	while (i <= back->id)
	{
		rooms[i].id = start->id;
		rooms[i].length = start->length;
		rooms[i].name = start->name;
		start = start->next;
		i++;
	}
	lemin->l = back->id + 1;
	algotithm(lemin, rooms);
}

int	main(void)
{
	char *line;
	t_room *start;
	t_room *back;
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
	while(get_next_line(0, &line) > 0)
	{
		if (line[0] == '\0')
			break;
		check_line(line, &back, lemin, start);
		free(line);
	}
	list_to_array(lemin, start, back);
	return (0);
}
