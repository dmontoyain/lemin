/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 04:09:53 by dmontoya          #+#    #+#             */
/*   Updated: 2018/03/06 21:51:19 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		checkdup_link(t_room *room, char *link)
{
	int		i;

	i = -1;
	while (++i < room->linkcount)
	{
		if (!ft_strcmp(room->links[i]->name, link))
			return (0);
	}
	return (1);
}

void	check_duproom(char *roomname, t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->roomcount)
	{
		if (!ft_strcmp(roomname, data->rooms[i]->name))
			error(0, 6);
	}
}

void	addlink_to_room(t_room *room, t_room *link, int array_size)
{
	int		i;
	int		j;
	int		newsize;
	t_room	**newarray;

	i = -1;
	j = 0;
	newsize = array_size + 1;
	if (!(newarray = (t_room **)malloc(sizeof(t_room *) * (newsize + 1))))
		return ;
	newarray[newsize] = 0;
	while (++i < array_size)
		newarray[j++] = room->links[i];
	newarray[j] = link;
	if (array_size)
		free(room->links);
	room->links = newarray;
}

void	addelem_to_doublestructarray(t_data *data, t_room *room, int array_size)
{
	int		i;
	int		j;
	int		newsize;
	t_room	**newstruct;

	i = -1;
	j = 0;
	newsize = array_size + 1;
	if (!(newstruct = (t_room **)malloc(sizeof(t_room *) * (newsize + 1))))
		return ;
	newstruct[newsize] = 0;
	while (++i < array_size)
		newstruct[j++] = data->rooms[i];
	newstruct[j] = room;
	if (array_size)
		free(data->rooms);
	data->rooms = newstruct;
}
