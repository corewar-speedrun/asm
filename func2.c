/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:03:01 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/10 16:12:57 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		split_cnt(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

char	*ft_strstrip(char *s, int i, int j)
{
	char	*ret;
	char	*tmp;
	int		len;

	len = 0;
	tmp = ft_strtrim(s);
	while (tmp[i] != '\0')
	{
		if (tmp[i] != ' ' && tmp[i] != '\t')
			len++;
		i++;
	}
	ret = ft_strnew(len);
	i = 0;
	while (j < len)
	{
		if (tmp[i] != ' ' && tmp[i] != '\t')
			ret[j++] = tmp[i++];
		else
			i++;
	}
	return (ret);
}
