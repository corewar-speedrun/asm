/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:00:59 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/10 19:48:57 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	p_live(char *a, t_a *s, int i, int j)
{
	char	*l;

	printf("zashlo\n");
	while (a[i] == ' ' || a[i] == '\t')
		i++;
	if (a[i++] != DIRECT_CHAR)
		return (dir_exp(a + i - 1));
	if (a[i] == LABEL_CHAR)
	{
		i++;
		while (ft_strchr(LABEL_CHARS, a[i + j]) && a[i + j] != 0)
			j++;
		l = ft_strsub(a, i, j);
		printf("|%s|%d|%d|\n", l, i, j);
		add_lc(l, s);
		ft_strdel(&l);
		i += j;
		add_4z(s);
	}
	else
	{
		printf("|%s|\n", a + i);
		if (a[i] == '-' && ft_isdigit(a[i + 1]))
		{
			printf("chislo -\n");
			while (ft_isdigit(a[i + 1 + j]))
				j++;
			l = ft_strsub(a, i, j + 1);
			add_4b(ft_atoi(l), s);
			ft_strdel(&l);
		}
		else if (ft_isdigit(a[i]))
		{
			printf("chislo +\n");
			while (ft_isdigit(a[i + j]))
				j++;
			l = ft_strsub(a, i, j);
			add_4b(ft_atoi(l), s);
			ft_strdel(&l);
		}
		else if (a[i] != 0)
			return (num_exp(a[i]));
		i += j;
	}
	while (a[i] != '\0')
	{
		while (a[i] == ' ' || a[i] == '\t')
			i++;
		if (a[i] == '#')
			while (a[i] != '\0')
				i++;
		else
			return (nc_exp(a[i]));
	}
	return (1);
}

int	p_ld(char *a)
{
	return (a[0]);
}

int	p_st(char *a)
{
	return (a[0]);
}

int	p_add(char *a)
{
	return (a[0]);
}

int	p_sub(char *a)
{
	return (a[0]);
}

int	p_and(char *a)
{
	return (a[0]);
}

int	p_or(char *a)
{
	return (a[0]);
}

int	p_xor(char *a)
{
	return (a[0]);
}

int	p_zjmp(char *a)
{
	return (a[0]);
}

int	p_ldi(char *a)
{
	return (a[0]);
}

int	p_sti(char *a)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg[3];

	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	if (!eval_reg(tmp2[0], &arg[0], 0))
		return (reg_exp(tmp2[0]));
	if (!eval_reg(tmp2[1], &arg[1], 1) && !eval_dir(tmp2[1], &arg[1], 1) &&
			!eval_ind(tmp2[1], &arg[1], 1))
		return (arg_exp(tmp2[1]));
	if (!eval_dir(tmp2[2], &arg[2], 2) && !eval_reg(tmp2[2], &arg[2], 2))
		return (0);
	printf("arg[%d], codage [%d], |%x|%x|%x|\n", 0, arg[0].codage.magic,
			arg[0].arg[0], arg[0].arg[1], arg[0].arg[2]);
	printf("~~~~~~~~~~~~~~~~~~sti arg |%s|\n", tmp1);
	return (a[0]);
}

int	p_fork(char *a)
{
	return (a[0]);
}

int	p_lld(char *a)
{
	return (a[0]);
}

int	p_lldi(char *a)
{
	return (a[0]);
}

int	p_lfork(char *a)
{
	return (a[0]);
}

int	p_aff(char *a)
{
	return (a[0]);
}
