/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:00:59 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/11 18:31:08 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//TODO в место вызова лейбла записывать
//"байт дефайна лейбла - байт начала операции, где он вызван"

int	p_live(char *a, t_a *s, int i, int j)
{
	char	*l;

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
		add_lc(l, s);
		ft_strdel(&l);
		i += j;
		add_4z(s);
	}
	else
	{
		if (a[i] == '-' && ft_isdigit(a[i + 1]))
		{
			while (ft_isdigit(a[i + 1 + j]))
				j++;
			l = ft_strsub(a, i, j + 1);
			add_4b(ft_atoi(l), s);
			ft_strdel(&l);
		}
		else if (ft_isdigit(a[i]))
		{
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

int	p_and(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (tmp2[0][0] == 'r')
	{
		if (!eval_reg(tmp2[0], &arg, 0))
			return (0);
	}
	else if (tmp2[0][0] == '%')
	{
		if (!eval_dir(tmp2[0], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[0], &arg, 1, s))
		return (arg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else if (tmp2[1][0] == '%')
	{
		if (!eval_dir(tmp2[1], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[1], &arg, 1, s))
		return (arg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (!eval_reg(tmp2[2], &arg, 2))
		return (reg_exp(tmp2[2]));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	//TODO	make it ifelse
	add_code(arg.codage, s);
	add_code(arg.arg[0], s);
	add_4z(s);
	add_code(arg.arg[2], s);
	printf("~~~~~~~~~~~and arg |%s|\n", tmp1);
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

int	p_zjmp(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (tmp1[0] == '%')
	{
		if (!eval_dir(tmp1, &arg, 0, s))
			return (0);
	}
	else
		return (dir_exp(a));
	/***************OUTPUT******************/
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	//TODO	make it ifelse
	printf("~~~~~~~~~~~zjmp arg |%s|\n", tmp1);
	add_2z(s);
	return (a[0]);
}

int	p_ldi(char *a)
{
	return (a[0]);
}

int	p_sti(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	arg;

	ft_bzero(&arg, sizeof(t_arg));
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!eval_reg(tmp2[0], &arg, 0))
		return (reg_exp(tmp2[0]));
	/****************ARG 2******************/
	if (tmp2[1][0] == 'r')
	{
		if (!eval_reg(tmp2[1], &arg, 1))
			return (0);
	}
	else if (tmp2[1][0] == '%')
	{
		if (!eval_dir(tmp2[1], &arg, 1, s))
			return (0);
	}
	else if (!eval_ind(tmp2[1], &arg, 1, s))
		return (arg_exp(tmp2[1]));
	/****************ARG 3******************/
	if (tmp2[2][0] == '%')
	{
		if (!eval_dir(tmp2[2], &arg, 2, s))
			return (0);
	}
	else if (tmp2[2][0] == 'r')
		if (!eval_reg(tmp2[2], &arg, 2))
			return (0);
	printf("codage [%d], |%x|%x|%x|\n", arg.codage,
			arg.arg[0], arg.arg[1], arg.arg[2]);
	/***************OUTPUT******************/
	//TODO	make it ifelse
	add_code(arg.codage, s);
	add_code(arg.arg[0], s);
	add_2z(s);
	add_2b(arg.arg[2], s);
	printf("~~~~~~~~~~~sti arg |%s|\n", tmp1);
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
