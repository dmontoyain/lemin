/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 00:53:42 by dmontoya          #+#    #+#             */
/*   Updated: 2018/03/06 21:51:36 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	if (argc > 1)
		usage();
	data = intitialize();
	parse(data);
	dijkstra(data);
	freeall(data);
	return (0);
}
