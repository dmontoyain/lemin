/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_touppercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:50:14 by dmontoya          #+#    #+#             */
/*   Updated: 2017/11/25 22:31:43 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_touppercase(char *str)
{
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
			*str = *str - 32;
		str++;
	}
}
