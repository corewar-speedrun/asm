/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:13:17 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/10 19:56:38 by dmaznyts         ###   ########.fr       */
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
			a->codage.bit[3 - w] = REG_CODE;
		}
	}
	return (1);
}

int		eval_dir(char *s, t_arg *a, int w)
{
	int i;

	i = 0;
	if (s[i] != '%')
		return (dir_exp(s));
	else
	{
		i++;
		if (s[i] == LABEL_CHAR)
		{
		
		}
	}
	return (s[0]);
}

int		eval_ind(char *s, t_arg *a, int w)
{
	(void)a;
	(void)w;
	return (s[0]);
}

int		eval_lable(void)
{
	return (0);
}
