/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:49:01 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 20:52:30 by dmaznyts         ###   ########.fr       */
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
	if (ch_op(s))
		return (1);
	else if (ch_l(s))
		return (1);
	else
		return (0);
}

void	s32(t_a *s)
{
	while (s->f[s->i] == ' ' || s->f[s->i] == '\t')
		s->i++;
}

void	scom(t_a *s)
{
	while (s->f[s->i] != '\n')
		s->i++;
	s->f[s->i] == '\n' ? s->curr_line++ : 0;
}

int		check_name(t_a *s)
{
	if (ft_strnequ(NAME_CMD_STRING, s->f + s->i,
				ft_strlen(NAME_CMD_STRING)))
	{
		if (s->prog_name[0] == '\0')
		{
			if (grep_name(s, 0, 0, 0) == 0)
				return (0);
		}
		else
		{
			ft_putstr("Duplicate .name in file\n");
			return (0);
		}
	}
	return (1);
}
