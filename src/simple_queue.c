/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 19:21:18 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/08/23 19:21:19 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

/*
** Добавление комнаты в список
*/

void	push_back(t_room **back, char *name)
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
**Добавление комнаты в очередь, при обходе в ширину
*/

void	add(t_queue *q, int i)
{
	while (q->next != NULL)
		q = q->next;
	q->next = (t_queue *)malloc(sizeof(t_queue));
	q->next->prev = q;
	q->next->next = NULL;
	q->next->number = q->number + 1;
	q->next->id = i;
}

char	**check_link_opt(char *line)
{
	char	**link;
	int		i;

	link = ft_strsplit(line, '-');
	i = 0;
	while (link[i++])
		;
	if (i != 3)
	{
		free_it(link);
		return (NULL);
	}
	return (link);
}
