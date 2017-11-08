/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:03:25 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/08 15:51:35 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		arg_parsa(unsigned char op, char *a/*, t_a *s*/)
{
	if (op == 9)
		return (p_zjmp(a));
	else if (op == 10)
		return (p_ldi(a));
	else if (op == 11)
		return (p_sti(a));
	else if (op == 12)
		return (p_fork(a));
	else if (op == 13)
		return (p_lld(a));
	else if (op == 14)
		return (p_lldi(a));
	else if (op == 15)
		return (p_lfork(a));
	else if (op == 16)
		return (p_aff(a));
	return (0);
}

int		arg_pars(unsigned char op, char *a, t_a *s)
{
	if (op == 1)
		return (p_live(a, s, 0, 0));
	else if (op == 2)
		return (p_ld(a));
	else if (op == 3)
		return (p_st(a));
	else if (op == 4)
		return (p_add(a));
	else if (op == 5)
		return (p_sub(a));
	else if (op == 6)
		return (p_and(a));
	else if (op == 7)
		return (p_or(a));
	else if (op == 8)
		return (p_xor(a));
	else
		return (arg_parsa(op, a/*, s*/));
	return (0);
}

int		add_op(char *op, t_a *s)
{
	int		st_p;
	char	*args;
	int		flag;

	add_code(ret_opcode(op, s), s);
	st_p = s->i;
	while (s->f[s->i] != '\n')
		s->i++;
	args = ft_strsub(s->f, st_p, s->i - st_p);
	//парсер аргументів з треканням виклику лейбла
	//	і вираховуванням codage
	if (arg_pars(ret_opcode(op, s), args, s))
		flag = 1;
	else
		return (1);
	ft_strdel(&args);
	printf("op |%s| args |%s|\n", op, args);
	return (flag);
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

void	add_4b(int add, t_a *s)
{

	union u_onebyte	z;

	z.magic = add;
	add_code(z.bit[3], s);
	add_code(z.bit[2], s);
	add_code(z.bit[1], s);
	add_code(z.bit[0], s);
	s->total_bytes += 4;
}

void	add_4z(t_a *s)
{
	add_code(0, s);
	add_code(0, s);
	add_code(0, s);
	add_code(0, s);
	s->total_bytes += 4;
}

void	add_lc(char *name, t_a *s)
{
	t_lc			*new;
	t_lc			*tmp;

	new = (t_lc*)malloc(sizeof(t_lc));
	new->name = ft_strdup(name);
	new->called_on = s->total_bytes;
	new->next = NULL;
	if (!s->lcallist)
		s->lcallist = new;
	else
	{
		tmp = s->lcallist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
