/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:13:17 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/16 22:08:38 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ch_ar(char *s)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != '-' && !ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int		eval_reg(char *s, t_arg *a, int w)
{
	int i;
	int	cod;

	i = 0;
	a->ditype[w] = -1;
	if (s[i] != 'r' || s[i + 1] == '\0')
		return (reg_exp(s));
	else
	{
		ch_ar(s + 1) ? (cod = ft_atoi(s + 1)) :
		(cod = 0);
		if (cod > REG_NUMBER || cod <= 0)
			return (reg_bad(cod));
		else
		{
			a->arg[w] = cod;
			a->codage = a->codage | REG_CODE;
			a->codage = a->codage << 2;
		}
	}
	return (1);
}

int		eval_dir(char *s, t_arg *a, int w, t_a *st)
{
	int i;

	i = 0;
	a->ditype[w] = 0;
	a->type[w] = 0;
	if (s[i] != DIRECT_CHAR)
		return (dir_exp(s));
	else
	{
		i++;
		if (s[i] == LABEL_CHAR)
		{
			if (s[1] == '\0')
				return (emplabcal());
			add_lc(s + i + 1, st);
			a->type[w] = 1;
		}
		else if (s[i] != '\0' && ch_ar(s + 1))
			a->arg[w] = ft_atoi(s + 1);
		else
			return (arg_exp(s));
		a->codage = a->codage | DIR_CODE;
		a->codage = a->codage << 2;
	}
	return (1);
}

int		eval_ind(char *s, t_arg *a, int w, t_a *st)
{
	int i;

	i = 0;
	a->type[w] = 0;
	a->ditype[w] = 1;
	if (s[0] == LABEL_CHAR)
	{
		if (s[1] == '\0')
			return (emplabcal());
		add_lc(s + 1, st);
		a->type[w] = 1;
	}
	else
	{
		if (!ch_ar(s))
			return (ind_exp(s));
		else
			a->arg[w] = ft_atoi(s);
	}
	a->codage = a->codage | IND_CODE;
	a->codage = a->codage << 2;
	return (1);
}
