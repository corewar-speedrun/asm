/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:13:17 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/12 13:59:06 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		eval_reg(char *s, t_arg *a, int w)
{
	int i;
	int	cod;

	i = 0;
	if (s[i] != 'r')
		return (reg_exp(s));
	else
	{
		cod = ft_atoi(s + 1);
		if (cod > REG_NUMBER)
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
	if (s[i] != '%')
		return (dir_exp(s));
	else
	{
		i++;
		if (s[i] == LABEL_CHAR)
			add_lc(s + i + 1, st);
		else
			a->arg[w] = ft_atoi(s + 1);
		a->codage = a->codage | DIR_CODE;
		a->codage = a->codage << 2;
	}
	return (1);
}

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

int		eval_ind(char *s, t_arg *a, int w, t_a *st)
{
	int i;

	i = 0;
	if (s[0] == LABEL_CHAR)
		add_lc(s, st);
	else
	{
		if (!ch_ar(s))
			return (ind_exp(s));
		else
		{
			a->arg[w] = ft_atoi(s);
			a->codage = a->codage | IND_CODE;
			a->codage = a->codage << 2;
		}
	}
	return (1);
}

int		eval_lable(void)
{
	return (0);
}
