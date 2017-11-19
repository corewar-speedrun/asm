/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:20:19 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/17 19:27:26 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	normefucker1(int add, t_pro *t, t_arg *tmp)
{
	if (tmp->ditype[0] == -1 && vopros(2, t->next->next->next))
	{
		if (tmp->ditype[1] == 1 && vopros(2, t->next->next->next))
			modify_2b(add, t->next->next->next);
		else if (vopros(4, t->next->next->next))
			modify_4b(add, t->next->next->next);
	}
	else if (tmp->ditype[0] == 1
		&& vopros(2, t->next->next->next->next))
	{
		if (tmp->ditype[1] == 1 && vopros(2, t->next->next->next->next))
			modify_2b(add, t->next->next->next->next);
		else if (vopros(4, t->next->next->next->next))
			modify_4b(add, t->next->next->next->next);
	}
	else
	{
		if (tmp->ditype[1] == 1
				&& vopros(2, t->next->next->next->next->next->next))
			modify_2b(add, t->next->next->next->next->next->next);
		else if (vopros(4, t->next->next->next->next->next->next))
			modify_4b(add, t->next->next->next->next->next->next);
	}
}

void	normefucker2(int add, t_pro *t, t_a *s, t_arg *tmp)
{
	if (t->byte == 6 || t->byte == 7 || t->byte == 8)
	{
		tmp = get_args(s, t->nb);
		if (tmp->type[0] == 1 && vopros(2, t->next->next))
		{
			if (tmp->ditype[0] == 1 && vopros(2, t->next->next))
				modify_2b(add, t->next->next);
			else if (vopros(4, t->next->next))
				modify_4b(add, t->next->next);
		}
		else if (tmp->type[1] == 1 && vopros(2, t->next->next->next))
		{
			normefucker1(add, t, tmp);
		}
	}
	else if (t->byte == 11)
	{
		tmp = get_args(s, t->nb);
		if (tmp->type[1] == 1 && vopros(2, t->next->next->next))
			modify_2b(add, t->next->next->next);
		else if (tmp->type[2] == 1 &&
				vopros(2, t->next->next->next->next))
			modify_2b(add, t->next->next->next->next);
	}
}

void	freespl(char **s)
{
	int	i;
	int	j;

	j = -1;
	i = split_cnt(s);
	while (++j < i)
		ft_strdel(&s[j]);
	free(s);
}

void	freeall(t_a *s)
{
	ft_strdel(&s->f);
	ft_bzero(s->prog_name, PROG_NAME_LENGTH);
	ft_bzero(s->comment, PROG_NAME_LENGTH);
	ft_strdel(&s->basename);
	ft_strdel(&s->prog_name_tmp);
	ft_strdel(&s->comment_tmp);
	s->total_bytes = 0;
	s->curr_line = 0;
	s->prog_size = 0;
	s->i = 0;
	freeoutput(s);
	freelablist(s);
	freelcallist(s);
	freeargs(s);
	s->nameflag = 0;
	s->commflag = 0;
}

char	*joincasino(char *s1, char *buf)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(s1, buf);
	ft_strdel(&s1);
	return (tmp);
}
