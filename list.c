/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:03:25 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/07 16:01:52 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	arg_pars();
	printf("op |%s| args |%s|\n", op, args);
}

void	add_code(unsigned char cod, t_a *s)
{
	t_pro			*new;
	t_pro			*tmp;

	new = (t_pro*)malloc(sizeof(t_pro));
	new->byte = cod;
	new->nb = 0;
	new->next = NULL;
	if (!s->output)
		s->output = new;
	else
	{
		tmp = s->output;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->nb = tmp->nb + 1;
	}
}
