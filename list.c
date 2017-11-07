/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:03:25 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/07 18:20:51 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	arg_parsa(unsigned char op, char *a)
{
	if (op == 9)
		p_zjmp(a);
	else if (op == 10)
		p_ldi(a);
	else if (op == 11)
		p_sti(a);
	else if (op == 12)
		p_fork(a);
	else if (op == 13)
		p_lld(a);
	else if (op == 14)
		p_lldi(a);
	else if (op == 15)
		p_lfork(a);
	else if (op == 16)
		p_aff(a);
}

void	arg_pars(unsigned char op, char *a)
{
	if (op == 1)
		p_live(a);
	else if (op == 2)
		p_ld(a);
	else if (op == 3)
		p_st(a);
	else if (op == 4)
		p_add(a);
	else if (op == 5)
		p_sub(a);
	else if (op == 6)
		p_and(a);
	else if (op == 7)
		p_or(a);
	else if (op == 8)
		p_xor(a);
	else
		arg_parsa(op, a);
}

void	add_op(char *op, t_a *s)
{
	int		st_p;
	char	*args;

	add_code(ret_opcode(op, s), s);
	st_p = s->i;
	while (s->f[s->i] != '\n')
		s->i++;
	args = ft_strsub(s->f, st_p, s->i - st_p);
	//парсер аргументів з треканням виклику лейбла
	//	і вираховуванням codage
	arg_pars(ret_opcode(op, s), args);
	ft_strdel(&args);
	printf("op |%s| args |%s|\n", op, args);
}

void	add_code(unsigned char cod, t_a *s)
{
	t_pro			*new;
	t_pro			*tmp;

	new = (t_pro*)malloc(sizeof(t_pro));
	new->byte = cod;
	new->nb = s->total_bytes++;
	new->next = NULL;
	if (!s->output)
		s->output = new;
	else
	{
		tmp = s->output;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
