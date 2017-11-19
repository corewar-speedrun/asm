/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:21:46 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/16 15:57:42 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	p_aff(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	*arg;
	int		f;

	f = 1;
	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	if (!r_arg(tmp1, arg, 0))
		f = 0;
	if (f)
	{
		arg->byte = s->total_bytes - 1;
		arg->codage = arg->codage << 4;
		badder(arg, s, 1, 2);
		add_arg(s, arg);
	}
	else
		free(arg);
	ft_strdel(&tmp1);
	return (f);
}

int	kostil(char *s)
{
	ft_strdel(&s);
	return (1);
}
