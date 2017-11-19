/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:38:11 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 21:38:27 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_code_h(unsigned char cod, t_a *s)
{
	t_pro	*new;

	new = (t_pro*)malloc(sizeof(t_pro));
	new->byte = cod;
	new->nb = s->total_bytes;
	new->next = s->output;
	s->output = new;
}

char	*ft_strndup(char *src)
{
	char	*ret;
	size_t	i;

	i = -1;
	ret = (char*)malloc(sizeof(char) * ft_strlen(src));
	ft_bzero(ret, ft_strlen(src));
	while (++i < ft_strlen(src) - 1)
		ret[i] = src[i];
	return (ret);
}

int		check_ext(t_a *s)
{
	int		flag;

	if (ft_strequ(s->av + (ft_strlen(s->av) - 2), ".s"))
	{
		flag = 1;
		s->basename = ft_strndup(s->av);
	}
	else
		flag = 0;
	return (flag);
}

int		last(char *s, int l, int b)
{
	char	*tmp;

	l = ft_strlen(s);
	b = l;
	while (s[l] != '\n')
		l--;
	tmp = ft_strsub(s, ++l, b);
	l = 0;
	while (tmp[l])
	{
		if (tmp[l] == '\t' || tmp[l] == ' ')
			l++;
		else if (tmp[l] == COMMENT_CHAR || tmp[l] == ';')
		{
			while (tmp[l] != '\0')
				l++;
			ft_strdel(&tmp);
			return (0);
		}
		else
			return (1);
	}
	ft_strdel(&tmp);
	return (0);
}
