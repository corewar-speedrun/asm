/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:00:59 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/08 13:40:03 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	p_live(char *a, t_a *s, int i, int j)
{
	char	*l;

	while (a[i] == ' ' || a[i] == '\t')
		i++;
	if (a[i++] != DIRECT_CHAR)
		return (dir_exp(a[i - 1]));
	if (a[i] == LABEL_CHAR)
	{
		while (ft_strchr(LABEL_CHARS, a[j]))
			j++;
		l = ft_strsub(a, i, j);
		add_lc(l, s);
		ft_strdel(&l);
		i += j;
	}
	while (a[i] != '\n')
	{
		if (a[i] == '#')
			while (a[i] != '\n' && a[i] != '\0')
				i++;
		i++;
	}
	add_4b(s);
	return (1);
}

int	p_ld(char *a)
{
	return (a[0]);
}

int	p_st(char *a)
{
	return (a[0]);
}

int	p_add(char *a)
{
	return (a[0]);
}

int	p_sub(char *a)
{
	return (a[0]);
}

int	p_and(char *a)
{
	return (a[0]);
}

int	p_or(char *a)
{
	return (a[0]);
}

int	p_xor(char *a)
{
	return (a[0]);
}

int	p_zjmp(char *a)
{
	return (a[0]);
}

int	p_ldi(char *a)
{
	return (a[0]);
}

int	p_sti(char *a)
{
	return (a[0]);
}

int	p_fork(char *a)
{
	return (a[0]);
}

int	p_lld(char *a)
{
	return (a[0]);
}

int	p_lldi(char *a)
{
	return (a[0]);
}

int	p_lfork(char *a)
{
	return (a[0]);
}

int	p_aff(char *a)
{
	return (a[0]);
}
