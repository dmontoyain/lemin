/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:31:06 by dmontoya          #+#    #+#             */
/*   Updated: 2018/03/06 21:52:00 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error(char *s, int e)
{
	ft_putstr("Error ");
	ft_putstr(s);
	if (e == 1)
		ft_putstr("no ants/invalid ant ammount entered.");
	else if (e == 2)
		ft_putstr("invalid room data.");
	else if (e == 4)
		ft_putstr("invalid ants input.");
	else if (e == 5)
		ft_putstr("Invalid link.");
	else if (e == 6)
		ft_putstr("duplicate rooms.");
	else if (e == 7)
		ft_putstr("Missing start/end.");
	else if (e == 8)
		ft_putstr("Missing links.");
	else if (e == 10)
		ft_putstr("No path found.");
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	usage(void)
{
	ft_putendl("Usage:");
	ft_putendl("Lemin reads a map from the standard output.");
	ft_putendl("Takes no arguments");
	ft_putendl("Map should be in the following format:");
	ft_putendl("number_of_ants");
	ft_putendl("the_rooms");
	ft_putendl("the_links");
	exit(EXIT_SUCCESS);
}
