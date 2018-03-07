/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:59:58 by dmontoya          #+#    #+#             */
/*   Updated: 2018/02/27 14:02:09 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t l1, size_t l2)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = ft_strnew(l1 + l2);
	if (!mem)
		return (NULL);
	while (i < l1)
		mem[i++] = *s1++;
	while (i < (l1 + l2))
		mem[i++] = *s2++;
	mem[i] = '\0';
	return (mem);
}
