/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 01:18:29 by dmontoya          #+#    #+#             */
/*   Updated: 2018/03/04 01:19:02 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s, char c)
{
	size_t	wc;
	size_t	i;

	wc = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
		{
			wc++;
			i++;
		}
		else if (s[i] != c && s[i - 1] != c)
			i++;
	}
	return (wc);
}
