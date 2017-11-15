/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:00:59 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 20:27:14 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	p_live(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	if (!d_arg(tmp1, s, arg, 0))
		return (0);
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
	if (!di_arg(tmp2[0], s, arg, 0))
		return (0);
	if (!r_arg(tmp2[1], arg, 1))
		return (0);
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
	if (!r_arg(tmp2[0], arg, 0))
		return (0);
	if (!ir_arg(tmp2[1], s, arg, 1))
		return (0);
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
	if (!r_arg(tmp2[0], arg, 0))
		return (0);
	if (!r_arg(tmp2[1], arg, 1))
		return (0);
	if (!r_arg(tmp2[2], arg, 2))
		return (0);
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
	if (!r_arg(tmp2[0], arg, 0))
		return (0);
	if (!r_arg(tmp2[1], arg, 1))
		return (0);
	if (!r_arg(tmp2[2], arg, 2))
		return (0);
	arg->byte = s->total_bytes - 1;
	badder(arg, s, 3, 2);
	add_arg(s, arg);
	return (1);
}
