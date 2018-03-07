/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 22:20:36 by dmontoya          #+#    #+#             */
/*   Updated: 2018/03/06 22:45:37 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reached_start(size_t ants_in_end, t_room *tmp, t_data *data)
{
	tmp->via->antid = tmp->antid + 1;
	if ((tmp->via->antid - 1) != ants_in_end)
		write(1, " ", 1);
	ft_printf("L%d-%s", tmp->via->antid, tmp->via->name);
	data->ants_in_start--;
}

void	ant_traffic(size_t ants_in_end, t_data *data)
{
	t_room		*tmp;

	while (ants_in_end < data->ants)
	{
		tmp = data->end;
		while (tmp->via)
		{
			if (tmp->end && tmp->antid)
				ants_in_end++;
			if ((tmp->antid = tmp->via->antid))
			{
				if ((tmp->antid - 1) != ants_in_end)
					write(1, " ", 1);
				ft_printf("L%d-%s", tmp->antid, tmp->name);
			}
			if (tmp->via->start && !data->ants_in_start)
				tmp->via->antid = 0;
			if (tmp->via->start && data->ants_in_start > 0)
				reached_start(ants_in_end, tmp, data);
			tmp = tmp->via;
		}
		write(1, "\n", 1);
	}
}

int		pathcomparer(int i, t_room *room)
{
	if (room->links[i]->start)
		return (0);
	if (room->links[i]->via &&
			((room->weight + room->links[i]->weight) < room->links[i]->weight))
		return (1);
	if (!room->links[i]->via)
		return (1);
	return (0);
}

void	findshortestpath(int i, int j, t_room *room, t_data *data)
{
	while (++i < room->linkcount && j < 2)
	{
		room->checked = 1;
		if (!j)
		{
			if (pathcomparer(i, room))
			{
				room->links[i]->weight += room->weight;
				room->links[i]->via = room;
			}
		}
		else
		{
			if (!room->end && !room->links[i]->start &&
					!room->links[i]->checked)
				findshortestpath(-1, 0, room->links[i], data);
		}
		if ((i + 1) == room->linkcount)
		{
			j++;
			i = -1;
		}
	}
}

void	dijkstra(t_data *data)
{
	findshortestpath(-1, 0, data->start, data);
	if (!data->end->via)
		error(0, 10);
	data->ants_in_start = data->ants;
	ant_traffic(0, data);
}
