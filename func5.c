/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:02:04 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/19 12:02:23 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	freeoutput(t_a *s)
{
	t_pro	*tmp;
	t_pro	*tmp2;

	if (s->output == NULL)
		return ;
	tmp = s->output;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	s->output = NULL;
}

void	freeargs(t_a *s)
{
	t_arg	*tmp;
	t_arg	*tmp2;

	if (!s->args)
		return ;
	tmp = s->args;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	s->args = NULL;
}

void	freelablist(t_a *s)
{
	t_l	*tmp;
	t_l	*tmp2;

	if (!s->lablist)
		return ;
	tmp = s->lablist;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->name);
		free(tmp);
		tmp = tmp2;
	}
	s->lablist = NULL;
}

void	freelcallist(t_a *s)
{
	t_lc	*tmp;
	t_lc	*tmp2;

	if (!s->lcallist)
		return ;
	tmp = s->lcallist;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->name);
		free(tmp);
		tmp = tmp2;
	}
	s->lcallist = NULL;
}

void	freeop(char **s)
{
	int i;

	i = -1;
	while (++i < 16)
		ft_strdel(&s[i]);
	free(s);
}
