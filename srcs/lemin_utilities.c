/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:54:53 by dmontoya          #+#    #+#             */
/*   Updated: 2018/03/06 22:16:47 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	freelink(t_link *link)
{
	free(link->room1);
	free(link->room2);
	free(link);
}

void	freeall(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->roomcount)
	{
		free(data->rooms[i]->name);
		free(data->rooms[i]->links);
		free(data->rooms[i]);
	}
	free(data->rooms);
	free(data);
}

void	start_link(char *link, t_data *data)
{
	if (ft_wordcount(link, ' ') != 1)
		error(0, 5);
	link_to_room(link, data);
	ft_putendl(link);
	free(link);
}

t_data	*intitialize(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->ants = 0;
	data->start = 0;
	data->end = 0;
	data->st = 0;
	data->en = 0;
	data->roomcount = 0;
	data->rooms = 0;
	return (data);
}

int		findcharpos(char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}
