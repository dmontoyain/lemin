/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvalidation_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 21:55:53 by dmontoya          #+#    #+#             */
/*   Updated: 2018/03/06 22:14:15 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		validatelink(int i, t_data *data, t_link *link)
{
	if (link->dashpos < 1)
		error(0, 5);
	if (link->dashpos == link->linklen)
		error(0, 5);
	while (++i < data->roomcount)
	{
		if (!ft_strcmp(data->rooms[i]->name, link->room1))
		{
			if (!checkdup_link(data->rooms[i], link->room2))
				return (0);
			link->room1ad = data->rooms[i];
		}
		else if (!ft_strcmp(data->rooms[i]->name, link->room2))
		{
			if (!checkdup_link(data->rooms[i], link->room1))
				return (0);
			link->room2ad = data->rooms[i];
		}
		if (link->room1ad && link->room2ad)
			break ;
	}
	if (!link->room1ad || !link->room2ad)
		error(0, 5);
	return (1);
}

int		validateants(char *s)
{
	int		i;

	if (ft_wordcount(s, ' ') != 1)
		error(0, 4);
	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (ft_atoi(s));
}

void	addroom(char **roomdata, t_data *data)
{
	t_room	*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return ;
	room->name = ft_strdup(roomdata[0]);
	room->links = NULL;
	if (data->st)
		data->start = room;
	if (data->en)
		data->end = room;
	room->end = data->en;
	room->start = data->st;
	room->linkcount = 0;
	room->checked = 0;
	room->antid = 0;
	room->weight = 1;
	room->via = NULL;
	data->en = 0;
	data->st = 0;
	addelem_to_doublestructarray(data, room, data->roomcount);
	data->roomcount++;
}

int		validaterooms(char *r, t_data *data)
{
	char	**roomdata;
	int		i;
	int		s;

	if (ft_wordcount(r, ' ') != 3)
		return (0);
	roomdata = ft_strsplit(r, ' ');
	s = 0;
	while (++s < 3)
	{
		i = -1;
		while (roomdata[s][++i])
			if (!ft_isdigit(roomdata[1][i]))
				error(0, 2);
	}
	check_duproom(roomdata[0], data);
	addroom(roomdata, data);
	while (s-- > 0)
		free(roomdata[s]);
	free(roomdata);
	return (1);
}
