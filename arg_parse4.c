/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:21:46 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 20:22:02 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	p_aff(char *a, t_a *s)
{
	char	*tmp1;
	t_arg	*arg;

	arg = arg_init();
	tmp1 = ft_strstrip(a, 0, 0);
	if (!r_arg(tmp1, arg, 0))
		return (0);
	arg->byte = s->total_bytes - 1;
	arg->codage = arg->codage << 4;
	badder(arg, s, 1, 2);
	add_arg(s, arg);
	return (1);
}
