/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:48:11 by dmontoya          #+#    #+#             */
/*   Updated: 2018/02/18 02:15:07 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	u_int64_t	ft_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= 48 && c <= 57);
	return ((c >= 48 && c <= 57) || (c >= 65 && c <= (65 + base - 10)));
}

u_int64_t			ft_atoi_base(char *str, u_int64_t base)
{
	u_int64_t	value;
	u_int64_t	sign;

	value = 0;
	if (base <= 1 || base > 36)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' ||
	*str == '\r' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_inbase(*str, base))
	{
		if (*str - 'A' >= 0)
			value = value * base + (*str - 'A' + 10);
		else
			value = value * base + (*str - '0');
		str++;
	}
	return (value * sign);
}
