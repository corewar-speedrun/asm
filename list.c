/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:03:25 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/28 22:44:21 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		arg_parsa(unsigned char op, char *a, t_a *s)
{
	if (op == 9)
		return (p_zjmp(a, s));
	else if (op == 10)
		return (p_ldi(a, s));
	else if (op == 11)
		return (p_sti(a, s));
	else if (op == 12)
		return (p_fork(a, s));
	else if (op == 13)
		return (p_lld(a, s));
	else if (op == 14)
		return (p_lldi(a, s));
	else if (op == 15)
		return (p_lfork(a, s));
	else if (op == 16)
		return (p_aff(a, s));
	return (0);
}

int		arg_pars(unsigned char op, char *a, t_a *s)
{
	if (op == 1)
		return (p_live(a, s));
	else if (op == 2)
		return (p_ld(a, s));
	else if (op == 3)
		return (p_st(a, s));
	else if (op == 4)
		return (p_add(a, s));
	else if (op == 5)
		return (p_sub(a, s));
	else if (op == 6)
		return (p_and(a, s));
	else if (op == 7)
		return (p_or(a, s));
	else if (op == 8)
		return (p_xor(a, s));
	else
		return (arg_parsa(op, a, s));
	return (0);
}

int		add_op(char *op, t_a *s)
{
	int		st_p;
	char	*args;
	int		flag;

	flag = 0;
	add_code(ret_opcode(op, s), s);
	st_p = s->i;
	while (s->f[s->i] != '\n' && s->f[s->i] != COMMENT_CHAR
			&& s->f[s->i] != ';' && s->f[s->i])
		(s->f[s->i] != COMMENT_CHAR && s->f[s->i] != ';') ? (s->i++) : 0;
	args = ft_strsub(s->f, st_p, s->i - st_p);
	if (arg_pars(ret_opcode(op, s), args, s))
		flag = 1;
	ft_strdel(&args);
	return (flag);
}
