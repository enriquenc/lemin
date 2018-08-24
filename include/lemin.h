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

typedef	struct	s_room
{
	int				id;
	int				length;
	int				is_path;
	char			*name;
	struct s_room	*next;
}				t_room;

typedef struct	s_lem
{
	int			start;
	int			end;
	int			l;
	int			links;
	long long	number_of_ants;
	int			**adj_matrix;
	int			**answer_mtrx;
}				t_lem;

typedef struct	s_queue
{
	int				id;
	int				number;
	struct s_queue	*next;
	struct s_queue	*prev;
}				t_queue;

typedef struct	s_alg
{
	int pred;
	int m;
	int min;
	int min_id;
}				t_alg;

void			error(const char *message);
void			check_coords(char **room);
void			check_spaces(char *line);
int				find_id(char *link, t_room **back, t_room *start);
int				check_sub(char *line, t_lem *lemin, t_room **back);
void			check_hash(char *line, t_lem *lemin, t_room **back);
void			check_ants(char *line, t_lem *lemin);
void			check_room(char *line, t_room **back, t_room *start);
void			valid_check(t_lem *lemin);
int				check_link(char *line, t_lem *lemin,
				t_room **back, t_room *start);
void			push_back(t_room **back, char *name);
void			give_memory(t_room **back, t_lem *lemin);
void			add(t_queue *q, int i);
void			list_to_array(t_lem *lemin, t_room *start,
				t_room *back);
void			algorithm(t_lem *lemin, t_room *rooms);
void			push_back(t_room **back, char *name);
void			add(t_queue *q, int i);
void			free_it(char **arr);

#endif
