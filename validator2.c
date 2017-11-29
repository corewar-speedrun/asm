/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:49:01 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/28 23:19:30 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		print_le(int i, t_a *s)
{
	ft_putstr("Lexical error at [");
	ft_putnbr(s->curr_line);
	ft_putchar(':');
	ft_putnbr(i);
	ft_putstr("]\n");
	return (0);
}

int		check(t_a *s)
{
	if (s->nameflag && s->commflag)
	{
		if (ch_op(s))
			return (1);
		else
			return (0);
	}
	else
		return (pe("No bot_name or bot_comment\n"));
}

void	s32(t_a *s)
{
	while (s->f[s->i] == ' ' || s->f[s->i] == '\t')
		s->i++;
}

void	scom(t_a *s)
{
	while (s->f[s->i] != '\n' && s->f[s->i])
		s->i++;
	s->f[s->i] == '\n' ? s->curr_line++ : 0;
}

int		normefucker5(char *cmp, int *f, int n, t_a *s)
{
	if (cmp[ft_strlen(cmp) - 1] == LABEL_CHAR)
	{
		*f = 1;
		if (cmp[0] == LABEL_CHAR)
			*f = emplabdef();
		if (extra(s->f + s->i + n, 0))
			*f = 0;
		add_la(cmp, s);
		s->i += n;
		if (*f == 1)
			ft_strdel(&cmp);
		return (*f);
	}
	return (*f);
}
