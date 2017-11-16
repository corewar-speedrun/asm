/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arger2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:40:25 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 20:42:08 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int		wtop(t_lc *to, t_l *from, t_a *s)
{
	t_pro	*lol;

	lol = s->output;
	while (lol->nb != to->called_on)
		lol = lol->next;
	chooser(from->defined - to->called_on, lol, s);
	return (1);
}

int		ass_lab(t_a *s)
{
	t_lc	*tmp;
	t_l		*t2;

	tmp = s->lcallist;
	while (tmp)
	{
		t2 = lab_def(tmp->name, s);
		if (!t2)
			return (ld_er(tmp->name));
		else
			wtop(tmp, t2, s);
		tmp = tmp->next;
	}
	return (1);
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
	ft_strdel(&tmp);
	return (ret);
}
