/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:03:01 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/10 16:12:57 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		split_cnt(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

char	*ft_strstrip(char *s, int i, int j)
{
	char	*ret;
	char	*tmp;
	int		len;

	len = 0;
	tmp = ft_strtrim(s);
	while (tmp[i] != '\0')
	{
		if (tmp[i] != ' ' && tmp[i] != '\t')
			len++;
		i++;
	}
	ret = ft_strnew(len);
	i = 0;
	while (j < len)
	{
		if (tmp[i] != ' ' && tmp[i] != '\t')
			ret[j++] = tmp[i++];
		else
			i++;
	}
	return (ret);
}

t_l	*lab_def(char *name, t_a *s)
{
	t_l	*tmp;

	tmp = s->lablist;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

void	chooser(int add, t_pro *t)
{
	if (t->byte == 1)
		modify_4b(add, t->next);
	else if (t->byte == 9 || t->byte == 12 || t->byte == 15)
		modify_2b(add, t->next);
	//дальше жопа с учитыванием кодирующего байта и аргумента
	// else if (t->byte == 2)
	// else if (t->byte == 3)
	// else if (t->byte == 4)
	// else if (t->byte == 5)
	// else if (t->byte == 6)
	// else if (t->byte == 7)
	// else if (t->byte == 8)
	// else if (t->byte == 10)
	// else if (t->byte == 11)
	// else if (t->byte == 13)
	// else if (t->byte == 14)
	// else if (t->byte == 16)
}

int		wtop(t_lc *to, t_l *from, t_a *s)
{
	t_pro	*lol;

	(void)from;
	lol = s->output;
	while (lol->nb != to->called_on)
		lol = lol->next;
	chooser(from->defined - to->called_on, lol);
	printf("byte called |%d|, op |%x|\n", to->called_on, lol->byte);
	return (1);
}

int		ass_lab(t_a *s)
{
	t_lc	*tmp;
	t_l		*t2;

	tmp = s->lcallist;
	while (tmp)
	{
		if ((t2 = lab_def(tmp->name, s)) == NULL)
			return (ld_er(tmp->name));
		else
			wtop(tmp, t2, s);
		tmp = tmp->next;
	}
	return (1);
}

void	badder(t_arg *arg, t_a *s, int args, int ls)
{
	int	i;

	i = -1;
	if (arg->codage)
		add_code(arg->codage, s);
	while (++i < args)
	{
		if (arg->ditype[i] == 1)		//if indirect
		{
			if (arg->type[i] == 1)		//if lable
				add_2z(s);
			else						//if num
				add_2b(arg->arg[i], s);
		}
		else if (arg->ditype[i] == 0)	//if direct
			if (arg->type[i] == 1)		//if lable
			{	
				if (ls == 4)
					add_4z(s);
				else
					add_2z(s);
			}
			else						//if num
			{	
				if (ls == 4)
					add_4b(arg->arg[i], s);
				else
					add_2b(arg->arg[i], s);
			}
		else if (arg->ditype[i] == -1)							//if reg
			add_code((unsigned char)arg->arg[i], s);
	}	
}