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

void error(void)
{
	ft_printf("ERROR\n");
	exit(0); 
}

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
		(*back)->length = NOT_CHECKED;
		(*back)->next = (t_room *)malloc(sizeof(t_room));
		(*back)->next->id = (*back)->id + 1;
		(*back)->next->name = ft_strdup(name);
		(*back) = (*back)->next;
	}
}

void check_hash(char *line, t_lem *lemin, t_room **back)
{
	if (ft_strequ(line + 2, "#start") && lemin->start == -1)
		lemin->start = (*back)->id + 1;
	else if (ft_strequ(line + 2, "#end") && lemin->end == -1)
		lemin->end = (*back)->id + 1;
}

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
			if (!ft_isdigit(room[i][j]))
				error();
			j++;
		}
		i++;
	}
	push_back(back, room[0]);
}

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

void algorithm(t_lem *lemin, t_room *start, t_room *back)
{
	int i;
	int j;

	i = 0;
	start->length = NOT_CHECKED;
	if (lemin->adj_matrix == NULL)
		error();
	while (i <= back->id)
	{
		j = 0;
		while (j <= back->id)
		{
			printf("%3d", lemin->adj_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(void)
{
	char *line;
	t_room *start;
	t_room *back;
	t_lem	*lemin;

	start = (t_room *)malloc(sizeof(t_room));
	start->name = NULL;
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
	algorithm(lemin, start, back);
	return (0);
}
