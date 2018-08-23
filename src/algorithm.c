/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:29:07 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/08/23 12:29:09 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

void	out(t_out *start, t_out *answer, t_lem *lemin)
{
	while (1)
	{
		answer = start;
		while (answer)
		{
			if (answer->n_ant != -1 && answer->n_ant != -2)
				ft_printf("L%d-%s ", answer->n_ant, answer->name);
			answer = answer->next;
		}
		if (ft_printf("\n") && start->n_ant == lemin->number_of_ants)
			break ;
		answer = start;
		while (answer)
		{
			if (answer->n_ant + 1 <= lemin->number_of_ants &&
					answer->n_ant != -2 && answer->n_ant != -1)
				answer->n_ant += 1;
			else if (answer->n_ant == -1 && answer->next &&
				answer->next->n_ant != -1 && answer->next->n_ant != -2)
				answer->n_ant = answer->next->n_ant;
			else if (answer->n_ant + 1 > lemin->number_of_ants)
				answer->n_ant = -2;
			answer = answer->next;
		}
	}
}

void	find_fastest_path(t_alg *ag, t_lem *lemin,
		t_room *rooms, t_out **answer)
{
	while (1)
	{
		ag->m = 0;
		ag->min = lemin->l;
		while (ag->m < lemin->l)
		{
			if (lemin->adj_matrix[ag->pred][ag->m] == 1 && rooms[ag->m].length
				< ag->min && rooms[ag->m].length != ALREADY_IN_PATH)
			{
				ag->min = rooms[ag->m].length;
				ag->min_id = ag->m;
			}
			ag->m++;
		}
		if (ag->min_id == lemin->start)
			break ;
		rooms[ag->min_id].length = ALREADY_IN_PATH;
		(*answer)->next = (t_out *)malloc(sizeof(t_out));
		(*answer)->next->prev = *answer;
		(*answer)->next->next = NULL;
		(*answer)->next->name = ft_strdup(rooms[ag->min_id].name);
		(*answer)->next->n_ant = -1;
		(*answer) = (*answer)->next;
		ag->pred = ag->min_id;
	}
}

void	find_fastest_path_start(t_lem *lemin, t_room *rooms)
{
	t_out *answer;
	t_out *end;
	t_out *start;
	t_alg *ag;

	answer = (t_out *)malloc(sizeof(t_out));
	answer->next = NULL;
	answer->prev = NULL;
	answer->n_ant = -1;
	answer->name = ft_strdup(rooms[lemin->end].name);
	end = answer;
	start = answer;
	rooms[lemin->end].length = ALREADY_IN_PATH;
	ag = (t_alg *)malloc(sizeof(t_alg));
	ag->pred = lemin->end;
	ag->min_id = 0;
	find_fastest_path(ag, lemin, rooms, &answer);
	answer->n_ant = 1;
	out(start, answer, lemin);
}

void	b_f_search(t_lem *lemin, t_room *rooms, t_queue *q)
{
	int i;

	while (1)
	{
		i = 0;
		while (i < lemin->l)
		{
			if (lemin->adj_matrix[q->id][i] == 1
				&& rooms[i].length == NOT_CHECKED)
			{
				rooms[i].length = rooms[q->id].length + 1;
				add(q, i);
			}
			i++;
		}
		if (q->next == NULL)
		{
			free(q);
			break ;
		}
		q = q->next;
		free(q->prev);
		q->prev = NULL;
	}
}

void	algorithm(t_lem *lemin, t_room *rooms)
{
	t_queue *q;

	valid_check(lemin);
	rooms[lemin->start].length = 0;
	q = (t_queue *)malloc(sizeof(t_queue));
	q->id = lemin->start;
	q->number = 0;
	q->prev = NULL;
	q->next = NULL;
	b_f_search(lemin, rooms, q);
	find_fastest_path_start(lemin, rooms);
}
