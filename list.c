/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:03:25 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/08 11:40:11 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		arg_parsa(unsigned char op, char *a)
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
}

int		arg_pars(unsigned char op, char *a)
{
	if (op == 1)
		return (p_live(a));
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
		return (arg_parsa(op, a));
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
	if (arg_pars(ret_opcode(op, s), args))
		flag = 1;
	else
		flag = 0;
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

void	add_lc(char<F8>, t_a *s)
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
