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
	if (lemin->number_of_ants <= 0 || lemin->number_of_ants > 2147483647)
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
	if(ft_atoi(room[1]) > 2147483647 || ft_atoi(room[2]) > 2147483647)
		error();
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
	lemin->answer_mtrx = (int **)malloc(sizeof(int *) * ((*back)->id + 1));
	i = 0;
	while (i <= (*back)->id)
	{
		lemin->answer_mtrx[i] = (int *)malloc(sizeof(int) * ((*back)->id + 1));
		ft_bzero(lemin->answer_mtrx[i], (*back)->id + 1);
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
	if (i == j)
		return ;
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

/*
** Проверка на то ли существует нужный путь
*/

void valid_check(t_lem *lemin)
{
	int i;
	int j;

	i = 0;
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
		error();
}

void algotithm(t_lem *lemin, t_room *rooms)
{
	int i;
	t_queue *q;

	valid_check(lemin);
	rooms[lemin->start].length = 0;
	q = (t_queue *)malloc(sizeof(t_queue));
	q->id = lemin->start;
	q->number = 0;
	q->prev = NULL;
	q->next = NULL;
	

	ft_printf("start = %d\nend = %3d\nlemin->l = %d\n", lemin->start, lemin->end, lemin->l);
	for(i = 0; i < lemin->l; i++)
	{
		for(int j = 0; j < lemin->l; j++)
			ft_printf("%3d", lemin->adj_matrix[i][j]);
		ft_printf("\n");
	}
	for(i = 0; i < lemin->l; i++)
		ft_printf("[%d] = %d\n", i, rooms[i].length);

	printf("start while\n\n");
	while(1)
	{
		i = 0;
		while (i < lemin->l)
		{
			if (lemin->adj_matrix[q->id][i] == 1 && rooms[i].length == NOT_CHECKED)
			{
				rooms[i].length = rooms[q->id].length + 1;
				add(q, i);
				ft_printf("%d\n", q->id);
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
	for(int j = 0; j < lemin->l; j++)
		ft_printf("rooms[%d].length = %d\n", j, rooms[j].length);
	int j;
	int prev;
	int min = lemin->l;
	int min_id = lemin->l;
	i = 0;
	if (lemin->adj_matrix[lemin->end][lemin->start] == 1)
	{
		lemin->answer_mtrx[i][lemin->end] = rooms[lemin->end].length;
		lemin->adj_matrix[lemin->end][lemin->start] = 0;
		lemin->adj_matrix[lemin->start][lemin->end] = 0;
		i++;
	}
	for(int f = 0; f < lemin->l; f++)
	{
		for(int j = 0; j < lemin->l; j++)
			ft_printf("%3d", lemin->adj_matrix[f][j]);
		ft_printf("\n");
	}
	ft_printf("\n\n");
	int prd = 1;
	while (i < lemin->l)
	{
		prev = lemin->end;
		lemin->answer_mtrx[i][lemin->end] = lemin->l;
		prd = lemin->l - 1;
		while (1)
		{
			min = lemin->l;
			min_id = lemin->l;
			j = 0;
			while (j < lemin->l)
			{
				if (lemin->adj_matrix[prev][j] == 1 && min > rooms[j].length && j != lemin->end && rooms[j].is_path != ALREADY_IN_PATH)
				{
					min = rooms[j].length;
					min_id = j;
				}
				j++;
			}
			if (min == lemin->l || min_id == lemin->l)
			{
				ft_bzero(lemin->answer_mtrx[i], lemin->l);
				for (int n = 0; n < lemin->l; n++)
					lemin->answer_mtrx[i][n] = 0;
				break ;
			}
			if (min == 0)
				break;
			lemin->adj_matrix[prev][min_id] = 0;
			lemin->adj_matrix[min_id][prev] = 0;
			rooms[min_id].is_path = ALREADY_IN_PATH;
			lemin->answer_mtrx[i][min_id] = prd;
			prd--;
			printf("\nansw_mtrx = %d\n", lemin->answer_mtrx[i][min_id]);
			prev = min_id;
		}
		
		i++;
	}

	for(i = 0; i < lemin->l; i++)
	{
		for(j = 0; j < lemin->l; j++)
			ft_printf("%3d", lemin->answer_mtrx[i][j]);
		ft_printf("\n");
	}
	for(j = 0; j < lemin->l; j++)
		ft_printf("rooms[%d].length = %d\n", j, rooms[j].length);
	int count = 0;
	int count1 = 0;
	int size = 0;
	while (count < lemin->l)
	{
		count1 = 0;
		while (count1 < lemin->l)
		{
			if (lemin->answer_mtrx[count][count1] != 0)
			{
				size++;
				break;
			}
			count1++;
		}
		if (count1 == lemin->l)
			break;
		count++;
	}
	t_out ***ans = (t_out ***)malloc(sizeof(t_out **) * size);
	count = 0;
	size = 0;
	int k = 0;
	while (count < size)
	{
		count1 = 0;
		while (count1 < lemin->l)
		{
			if (lemin->answer_mtrx[count][count1] != 0)
				size++;
			count1++;
		}
		ans[count] = (t_out **)malloc(sizeof(t_out *) * size);
		count++;
		
		k = lemin->l - size;
		int l = 0;
		while (k <= lemin->l)
		{
			count1 = 0;
			while (count1 < lemin->l)
			{
				if (lemin->answer_mtrx[count][count1] == k)
				{
					lemin->answer_mtrx[count][count1] = 0;
					ans[count][l]->name = ft_strdup(rooms[count1].name);
					ans[count][l]->n_ant = 0;
					ft_printf("%s ", ans[count][l]->name);
				}
				count1++;
			}
			k++;
		}
		ft_printf("\n");
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
		rooms[i].is_path = 0;
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
		{
			ft_printf("\n");
			break;
		}
		check_line(line, &back, lemin, start);
		ft_printf("%s\n", line);
		free(line);
	}
	ft_printf("\n");
	list_to_array(lemin, start, back);
	return (0);
}
