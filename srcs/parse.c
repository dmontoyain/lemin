/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 21:50:08 by dmontoya          #+#    #+#             */
/*   Updated: 2018/03/06 22:12:48 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	link_to_room(char *li, t_data *data)
{
	t_link	*link;
	int		linkend;

	link = (t_link *)malloc(sizeof(t_link));
	link->room1ad = 0;
	link->room2ad = 0;
	link->dashpos = findcharpos(li, '-');
	link->linklen = ft_strlen(li);
	linkend = link->linklen - (link->dashpos + 1);
	link->room1 = ft_strsub(li, 0, link->dashpos);
	link->room2 = ft_strsub(li, link->dashpos + 1, linkend);
	if (!validatelink(-1, data, link))
	{
		freelink(link);
		return ;
	}
	addlink_to_room(link->room1ad, link->room2ad, link->room1ad->linkcount);
	addlink_to_room(link->room2ad, link->room1ad, link->room2ad->linkcount);
	link->room1ad->linkcount++;
	link->room2ad->linkcount++;
	freelink(link);
}

void	parse_links(int ret, char *link, t_data *data)
{
	char	*l;

	start_link(link, data);
	while ((ret = get_next_line(0, &l)) >= 0)
	{
		if (!ft_wordcount(l, ' '))
		{
			if (!ret)
			{
				free(l);
				break ;
			}
			error(0, 3);
		}
		else if (l[0] == '#')
			continue;
		else
		{
			if (ft_wordcount(l, ' ') != 1)
				error(0, 5);
			link_to_room(l, data);
		}
		ft_putendl(l);
		free(l);
	}
}

char	*parse_rooms(t_data *data)
{
	char	*l;
	int		i;

	i = -1;
	l = NULL;
	while (get_next_line(0, &l) >= 0)
	{
		ft_putendl(l);
		if (!ft_wordcount(l, ' '))
			error(0, 3);
		else if (!ft_strcmp(l, "##start"))
			data->st = 1;
		else if (!ft_strcmp(l, "##end"))
			data->en = 1;
		else if (l[0] == '#')
			continue;
		else if (!validaterooms(l, data))
			break ;
		free(l);
	}
	if (!data->start || !data->end)
		error(0, 7);
	if (!l)
		error(0, 8);
	return (l);
}

void	parse_ants(t_data *data)
{
	char	*l;

	l = NULL;
	while (get_next_line(0, &l) >= 0)
	{
		if (!ft_wordcount(l, ' '))
			error(0, 3);
		else if (l[0] == '#')
			continue;
		else if (!(data->ants = validateants(l)))
			error(0, 1);
		ft_putendl(l);
		free(l);
		if (data->ants)
			break ;
	}
}

void	parse(t_data *data)
{
	char	*remlink;
	int		ret;

	ret = 0;
	parse_ants(data);
	remlink = parse_rooms(data);
	parse_links(ret, remlink, data);
	write(1, "\n", 1);
}
