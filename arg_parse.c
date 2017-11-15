/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:00:59 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/14 18:58:46 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	p_live(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (!d_arg(tmp1, s, arg, 0))
		return (0);
	/***************OUTPUT******************/
	arg->codage = 0;
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 1, 4);
	add_arg(s, arg);
	return (1);
}

int	p_ld(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 2)
		return (two_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!di_arg(tmp2[0], s, arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!r_arg(tmp2[1], arg, 1))
		return (0);
	/***************OUTPUT******************/
	arg->codage = arg->codage << 2;
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 2, 4);
	add_arg(s, arg);
	return (1);
}

int	p_st(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 2)
		return (two_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!r_arg(tmp2[0], arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!ir_arg(tmp2[1], s, arg, 1))
		return (0);
	/***************OUTPUT******************/
	arg->codage = arg->codage << 2;
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 2, 2);
	add_arg(s, arg);
	return (1);
}

int	p_add(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!r_arg(tmp2[0], arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!r_arg(tmp2[1], arg, 1))
		return (0);
	/****************ARG 3******************/
	if (!r_arg(tmp2[2], arg, 2))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 3, 2);
	add_arg(s, arg);
	return (1);
}

int	p_sub(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!r_arg(tmp2[0], arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!r_arg(tmp2[1], arg, 1))
		return (0);
	/****************ARG 3******************/
	if (!r_arg(tmp2[2], arg, 2))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 3, 2);
	add_arg(s, arg);
	return (1);
}

int	p_and(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!rdi_arg(tmp2[0], s, arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!rdi_arg(tmp2[1], s, arg, 1))
		return (0);
	/****************ARG 3******************/
	if (!r_arg(tmp2[2], arg, 2))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 3, 4);
	add_arg(s, arg);
	return (1);
}

int	p_or(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!rdi_arg(tmp2[0], s, arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!rdi_arg(tmp2[1], s, arg, 1))
		return (0);
	/****************ARG 3******************/
	if (!r_arg(tmp2[2], arg, 2))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 3, 4);
	add_arg(s, arg);
	return (1);
}

int	p_xor(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!rdi_arg(tmp2[0], s, arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!rdi_arg(tmp2[1], s, arg, 1))
		return (0);
	/****************ARG 3******************/
	if (!r_arg(tmp2[2], arg, 2))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 3, 4);
	add_arg(s, arg);
	return (1);
}

int	p_zjmp(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (!d_arg(tmp1, s, arg, 0))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	arg->codage = 0;
	badder(arg, s, 1, 2);
	add_arg(s, arg);
	return (1);
}

int	p_ldi(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!rdi_arg(tmp2[0], s, arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!rd_arg(tmp2[1], s, arg, 1))
		return (0);
	/****************ARG 3******************/
	if (!r_arg(tmp2[2], arg, 2))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 3, 2);
	add_arg(s, arg);
	return (1);
}

int	p_sti(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!r_arg(tmp2[0], arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!rdi_arg(tmp2[1], s, arg, 1))
		return (0);
	/****************ARG 3******************/
	if (!rd_arg(tmp2[2], s, arg, 2))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 3, 2);
	add_arg(s, arg);
	return (1);
}

int	p_fork(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (!d_arg(tmp1, s, arg, 0))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	arg->codage = 0;
	badder(arg, s, 1, 2);
	add_arg(s, arg);
	return (1);
}

int	p_lld(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 2)
		return (two_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!di_arg(tmp2[0], s, arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!r_arg(tmp2[1], arg, 1))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	arg->codage = arg->codage << 2;
	badder(arg, s, 2, 4);
	add_arg(s, arg);
	return (1);
}

int	p_lldi(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		return (three_ae(split_cnt(tmp2)));
	/****************ARG 1******************/
	if (!rdi_arg(tmp2[0], s, arg, 0))
		return (0);
	/****************ARG 2******************/
	if (!rd_arg(tmp2[1], s, arg, 1))
		return (0);
	/****************ARG 3******************/
	if (!r_arg(tmp2[2], arg, 2))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 3, 2);
	add_arg(s, arg);
	return (1);
}

int	p_lfork(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (!d_arg(tmp1, s, arg, 0))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	arg->codage = 0;
	badder(arg, s, 1, 2);
	add_arg(s, arg);
	return (1);
}

int	p_aff(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	/****************ARG 1******************/
	if (!r_arg(tmp1, arg, 0))
		return (0);
	/***************OUTPUT******************/
	arg->byte = s->total_bytes - 1;
	arg->codage = arg->codage << 4;
	badder(arg, s, 1, 2);
	add_arg(s, arg);
	return (1);
}
