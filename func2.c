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
	if (!s)
		return (-1);
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
	if (!tmp)
		return (NULL);
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
	unsigned char	b;

	b = 0;
	if (t->byte == 1)
		modify_4b(add, t->next);
	else if (t->byte == 9 || t->byte == 12 || t->byte == 15)
		modify_2b(add, t->next);
	else if (t->byte == 3)
		modify_2b(add, t->next->next->next);
	else if (t->byte == 2 || t->byte == 13)
	{
		b = (t->next->byte << 6) >> 6;
		b ? (modify_4b(add, t->next->next)) : (modify_2b(add, t->next->next));
		t->next->byte = t->next->byte & 0xFC;
	}
	//дальше жопа с учитыванием кодирующего байта и позиции аргумента
	// лейблов может быть два, в двух аргументах
	//
	// else if (t->byte == 10 || t->byte == 14)
	// {
	// 	b = (t->next->byte << 6) >> 6;
	// 	b ? (modify_4b(add, t->next->next)) : (modify_2b(add, t->next->next));
	// 	t->next->byte = 0xFC & t->next->byte;
	// }
	// else if (t->byte == 6)
	// else if (t->byte == 7)
	// else if (t->byte == 8)
	// else if (t->byte == 11)
}

int		wtop(t_lc *to, t_l *from, t_a *s)
{
	t_pro	*lol;

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
		if (arg->ditype[i] == 1)			//if indirect
		{
			if (arg->type[i] == 1)			//if lable
				add_2z(s);
			else							//if num
				add_2b(arg->arg[i], s);
		}
		else if (arg->ditype[i] == 0)		//if direct
			if (arg->type[i] == 1)			//if lable
			{	
				if (ls == 4)
					add_4z(s);
				else
					add_2z(s);
			}
			else							//if num
			{	
				if (ls == 4)
					add_4b(arg->arg[i], s);
				else
					add_2b(arg->arg[i], s);
			}
		else if (arg->ditype[i] == -1)		//if reg
			add_code((unsigned char)arg->arg[i], s);
	}	
}

int		di_arg(char *tmp, t_a *s, t_arg *arg, int w)
{
	if (tmp[0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp, arg, w, s))
			return (0);
	}
	else if (tmp[0] != 'r')
	{
		if (!eval_ind(tmp, arg, w, s))
			return (0);
	}
	else
		return (arg_exp(tmp));
	return (1);
}

int		r_arg(char *tmp, t_arg *arg, int w)
{	
	if (tmp[0] == 'r')
	{
		if (!eval_reg(tmp, arg, w))
			return (0);
	}
	else
		return (reg_exp(tmp));
	return (1);
}

int		d_arg(char *tmp, t_a *s, t_arg *arg, int w)
{
	if (tmp[0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp, arg, w, s))
			return (0);
	}
	else
		return (dir_exp(tmp));
	return (1);
}

int		ir_arg(char *tmp, t_a *s, t_arg *arg, int w)
{
	if (tmp[0] == 'r')
	{
		if (!eval_reg(tmp, arg, w))
			return (0);
	}
	else if (tmp[0] != DIRECT_CHAR)
	{
		if (!eval_ind(tmp, arg, w, s))
			return (0);
	}
	else
		return (reg_exp(tmp));
	return (1);
}

int		rdi_arg(char *tmp, t_a *s, t_arg *arg, int w)
{
	if (tmp[0] == 'r')
	{
		if (!eval_reg(tmp, arg, w))
			return (0);
	}
	else if (tmp[0] == DIRECT_CHAR) 
	{
		if (!eval_dir(tmp, arg, w, s))
			return (0);
	}
	else if (!eval_ind(tmp, arg, w, s))
		return (arg_exp(tmp));
	return (1);
}

int		rd_arg(char *tmp, t_a *s, t_arg *arg, int w)
{
	if (tmp[0] == 'r')
	{
		if (!eval_reg(tmp, arg, w))
			return (0);
	}
	else if (tmp[0] == DIRECT_CHAR)
	{
		if (!eval_dir(tmp, arg, w, s))
			return (0);
	}
	else
		return (arg_exp(tmp));
	return (1);
}

t_arg	*arg_init(void)
{
	t_arg	*arg;
	int		i;

	arg = (t_arg*)malloc(sizeof(t_arg));
	i = -1;
	while (++i < 3)
		arg->arg[i] = 0;
	i = -1;
	while (++i < 3)
		arg->type[i] = 0;
	i = -1;
	while (++i < 3)
		arg->ditype[i] = 0;
	arg->codage = 0;
	arg->byte = 0;
	arg->next = NULL;
	return (arg);
}