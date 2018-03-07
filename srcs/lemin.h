/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:54:07 by dmontoya          #+#    #+#             */
/*   Updated: 2018/03/06 22:15:28 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"
# include "../printf/libftprintf.h"

typedef struct		s_room
{
	char			*name;
	int				start;
	int				end;
	size_t			antid;
	int				weight;
	int				checked;
	int				linkcount;
	struct s_room	*via;
	struct s_room	**links;
}					t_room;

typedef struct		s_link
{
	int				linklen;
	int				dashpos;
	char			*room1;
	char			*room2;
	t_room			*room1ad;
	t_room			*room2ad;
}					t_link;

typedef struct		s_data
{
	int				st;
	int				en;
	int				roomcount;
	size_t			ants;
	size_t			ants_in_start;
	t_room			*start;
	t_room			*end;
	t_room			**rooms;
}					t_data;

void				dijkstra(t_data *data);
void				parse(t_data *data);
void				error(char *s, int e);
void				usage(void);
int					validaterooms(char *r, t_data *data);
int					validatelink(int i, t_data *data, t_link *link);
int					validateants(char *s);
int					checkdup_link(t_room *room, char *link);
void				check_duproom(char *roomname, t_data *data);
int					findcharpos(char *str, int c);
void				start_link(char *link, t_data *data);
void				link_to_room(char *li, t_data *data);
void				addlink_to_room(t_room *room, t_room *link, int array_size);
void				addelem_to_doublestructarray(t_data *d, t_room *rm, int sz);
t_data				*intitialize(void);
void				freelink(t_link *link);
void				freeall(t_data *data);

#endif
