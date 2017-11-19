/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:20:27 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/16 15:57:01 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	p_and(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;
	int		f;

	f = 1;
	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		f = three_ae(split_cnt(tmp2));
	(f && !rdi_arg(tmp2[0], s, arg, 0)) ? (f = 0) : 0;
	(f && !rdi_arg(tmp2[1], s, arg, 1)) ? (f = 0) : 0;
	(f && !r_arg(tmp2[2], arg, 2)) ? (f = 0) : 0;
	if (f)
	{
		arg->byte = s->total_bytes - 1;
		badder(arg, s, 3, 4);
		add_arg(s, arg);
	}
	else
		free(arg);
	freespl(tmp2);
	ft_strdel(&tmp1);
	return (f);
}

int	p_or(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;
	int		f;

	f = 1;
	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		f = three_ae(split_cnt(tmp2));
	(f && !rdi_arg(tmp2[0], s, arg, 0)) ? (f = 0) : 0;
	(f && !rdi_arg(tmp2[1], s, arg, 1)) ? (f = 0) : 0;
	(f && !r_arg(tmp2[2], arg, 2)) ? (f = 0) : 0;
	if (f)
	{
		arg->byte = s->total_bytes - 1;
		badder(arg, s, 3, 4);
		add_arg(s, arg);
	}
	else
		free(arg);
	freespl(tmp2);
	ft_strdel(&tmp1);
	return (f);
}

int	p_xor(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;
	int		f;

	f = 1;
	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		f = three_ae(split_cnt(tmp2));
	(f && !rdi_arg(tmp2[0], s, arg, 0)) ? (f = 0) : 0;
	(f && !rdi_arg(tmp2[1], s, arg, 1)) ? (f = 0) : 0;
	(f && !r_arg(tmp2[2], arg, 2) && f) ? (f = 0) : 0;
	if (f)
	{
		arg->byte = s->total_bytes - 1;
		badder(arg, s, 3, 4);
		add_arg(s, arg);
	}
	else
		free(arg);
	freespl(tmp2);
	ft_strdel(&tmp1);
	return (f);
}

int	p_zjmp(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	*arg;
	int		f;

	f = 1;
	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	if (!d_arg(tmp1, s, arg, 0))
		f = 0;
	if (f)
	{
		arg->byte = s->total_bytes - 1;
		arg->codage = 0;
		badder(arg, s, 1, 2);
		add_arg(s, arg);
	}
	else
		free(arg);
	ft_strdel(&tmp1);
	return (f);
}

int	p_ldi(char *a, t_a *s)
{
	char	*tmp1;
	char	**tmp2;
	t_arg	*arg;
	int		f;

	f = 1;
	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	tmp2 = ft_strsplit(tmp1, SEPARATOR_CHAR);
	if (split_cnt(tmp2) != 3)
		f = three_ae(split_cnt(tmp2));
	(f && !rdi_arg(tmp2[0], s, arg, 0)) ? (f = 0) : 0;
	(f && !rd_arg(tmp2[1], s, arg, 1)) ? (f = 0) : 0;
	(f && !r_arg(tmp2[2], arg, 2)) ? (f = 0) : 0;
	if (f)
	{
		arg->byte = s->total_bytes - 1;
		badder(arg, s, 3, 2);
		add_arg(s, arg);
	}
	else
		free(arg);
	freespl(tmp2);
	ft_strdel(&tmp1);
	return (f);
}
