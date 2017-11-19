/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:03:01 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 20:42:11 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		split_cnt(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != NULL)
		i++;
	return (i);
}

t_l		*lab_def(char *name, t_a *s)
{
	t_l	*tmp;

	tmp = s->lablist;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_arg	*get_args(t_a *s, int byte)
{
	t_arg	*tmp;

	tmp = s->args;
	while (tmp)
	{
		if (tmp->byte == byte)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	chooser(int add, t_pro *t, t_a *s)
{
	unsigned char	b;
	t_arg			*tmp;
	int				i;

	tmp = NULL;
	i = -1;
	b = 0;
	if (t->byte == 1)
		modify_4b(add, t->next);
	else if (t->byte == 9 || t->byte == 12 || t->byte == 15)
		modify_2b(add, t->next);
	else if (t->byte == 3)
		modify_2b(add, t->next->next->next);
	else if (t->byte == 2 || t->byte == 13)
		normefucker4(add, t, s, tmp);
	else if (t->byte == 10 || t->byte == 14)
		normefucker3(add, t, s, tmp);
	else
		normefucker2(add, t, s, tmp);
}

void	badder(t_arg *arg, t_a *s, int args, int ls)
{
	int	i;

	i = -1;
	if (arg->codage)
		add_code(arg->codage, s);
	while (++i < args)
	{
		if (arg->ditype[i] == 1)
		{
			if (arg->type[i] == 1)
				add_2z(s);
			else
				add_2b(arg->arg[i], s);
		}
		else if (arg->ditype[i] == 0)
			badder2(arg, ls, i, s);
		else if (arg->ditype[i] == -1)
			add_code((unsigned char)arg->arg[i], s);
	}
}
