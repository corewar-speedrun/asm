/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arger1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:39:07 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 20:43:32 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
