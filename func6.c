/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:35:07 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/19 12:35:21 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	normefucker3(int add, t_pro *t, t_a *s, t_arg *tmp)
{
	tmp = get_args(s, t->nb);
	if (tmp->type[0] == 1 && vopros(2, t->next->next))
		modify_2b(add, t->next->next);
	else if (tmp->type[1] == 1)
	{
		if (tmp->ditype[0] == -1 && vopros(2, t->next->next->next))
			modify_2b(add, t->next->next->next);
		else if (vopros(2, t->next->next->next->next))
			modify_2b(add, t->next->next->next->next);
	}
}

void	normefucker4(int add, t_pro *t, t_a *s, t_arg *tmp)
{
	tmp = get_args(s, t->nb);
	if (tmp->ditype[0] == 1)
		modify_2b(add, t->next->next);
	else
		modify_4b(add, t->next->next);
}

void	badder2(t_arg *arg, int ls, int i, t_a *s)
{
	if (arg->type[i] == 1)
	{
		if (ls == 4)
			add_4z(s);
		else
			add_2z(s);
	}
	else
	{
		if (ls == 4)
			add_4b(arg->arg[i], s);
		else
			add_2b(arg->arg[i], s);
	}
}
