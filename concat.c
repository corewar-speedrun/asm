/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:34:01 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 21:34:03 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	putmagic(t_a *s)
{
	union u_onebyte	z;

	z.magic = COREWAR_EXEC_MAGIC;
	add_code_h(z.bit[0], s);
	add_code_h(z.bit[1], s);
	add_code_h(z.bit[2], s);
	add_code_h(z.bit[3], s);
}

void	putname(t_a *s)
{
	int	l2;
	int	len;

	len = PROG_NAME_LENGTH + 1;
	l2 = ft_strlen(s->prog_name);
	while (len > 0)
	{
		if (s->prog_name[len] != 0 && len <= l2)
		{
			add_code_h(s->prog_name[len], s);
			l2--;
		}
		else
			add_code_h(0, s);
		len--;
	}
}

void	putcomment(t_a *s)
{
	int	len;
	int	l2;

	l2 = ft_strlen(s->comment);
	len = COMMENT_LENGTH + 1;
	while (len > 0)
	{
		if (s->comment[len] != 0 && len <= l2)
		{
			add_code_h(s->comment[len], s);
			l2--;
		}
		else
			add_code_h(0, s);
		len--;
	}
}

void	putident(t_a *s)
{
	int id;

	id = 0;
	if ((PROG_NAME_LENGTH + 1) % 4 != 0)
		id = 4 - (PROG_NAME_LENGTH + 1) % 4;
	while (id-- > 0)
		add_code_h(0, s);
}

void	putsize(t_a *s)
{
	union u_onebyte	z;

	z.magic = s->total_bytes;
	add_code_h(z.bit[0], s);
	add_code_h(z.bit[1], s);
	add_code_h(z.bit[2], s);
	add_code_h(z.bit[3], s);
}
