/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:13:01 by dmontoya          #+#    #+#             */
/*   Updated: 2018/02/09 21:26:53 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	strtohex(char *str)
{
	unsigned long long	result;

	result = 0;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'f')
			result = result * 16 + (*str - 'a' + 10);
		else if (*str >= 'A' && *str <= 'F')
			result = result * 16 + (*str - 'A' + 10);
		else if (*str >= '0' && *str <= '9')
			result = result * 16 + (*str - 48);
		else
			return (0);
		str++;
	}
	return (result);
}
