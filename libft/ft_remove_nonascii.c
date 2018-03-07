/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_nonascii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:57:24 by dmontoya          #+#    #+#             */
/*   Updated: 2018/02/27 14:01:48 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remove_nonascii(char *s, int n)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	ret = (char *)malloc(sizeof(char) * n);
	ret[n] = '\0';
	ft_bzero(ret, n);
	while (++i < n)
	{
		if (ft_isprint(s[i]) || s[i] == '\n' || s[i] == '\t')
			ret[j++] = s[i];
	}
	tmp = ft_strsub(ret, 0, j);
	free(ret);
	free(s);
	ret = tmp;
	return (ret);
}
