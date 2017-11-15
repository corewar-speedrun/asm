/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:34:05 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 21:23:00 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_la(char *l, t_a *s)
{
	t_l		*new;
	t_l		*tmp;

	new = (t_l*)malloc(sizeof(t_l));
	new->name = ft_strdup(l);
	new->name[ft_strlen(l) - 1] = '\0';
	new->defined = s->total_bytes;
	new->next = NULL;
	if (!s->lablist)
		s->lablist = new;
	else
	{
		tmp = s->lablist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	add_lc(char *name, t_a *s)
{
	t_lc			*new;
	t_lc			*tmp;

	new = (t_lc*)malloc(sizeof(t_lc));
	new->name = ft_strdup(name);
	s->total_bytes ? (new->called_on = s->total_bytes - 1) :
		(new->called_on = s->total_bytes);
	new->next = NULL;
	if (!s->lcallist)
		s->lcallist = new;
	else
	{
		tmp = s->lcallist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	add_arg(t_a *s, t_arg *add)
{
	if (!s->args)
		s->args = add;
	else
	{
		add->next = s->args;
		s->args = add;
	}
}
