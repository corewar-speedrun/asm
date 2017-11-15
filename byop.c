/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:30:23 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 20:33:22 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_4b(int add, t_a *s)
{
	union u_onebyte	z;

	z.magic = add;
	add_code(z.bit[3], s);
	add_code(z.bit[2], s);
	add_code(z.bit[1], s);
	add_code(z.bit[0], s);
}

void	add_2b(int add, t_a *s)
{
	union u_onebyte	z;

	z.magic = add;
	add_code(z.bit[1], s);
	add_code(z.bit[0], s);
}

void	modify_4b(int add, t_pro *t)
{
	union u_onebyte	z;

	z.magic = add;
	t->byte = z.bit[3];
	t->next->byte = z.bit[2];
	t->next->next->byte = z.bit[1];
	t->next->next->next->byte = z.bit[0];
}

void	modify_2b(int add, t_pro *t)
{
	union u_onebyte	z;

	z.magic = add;
	t->byte = z.bit[1];
	t->next->byte = z.bit[0];
}

void	add_4z(t_a *s)
{
	add_code(0, s);
	add_code(0, s);
	add_code(0, s);
	add_code(0, s);
}
