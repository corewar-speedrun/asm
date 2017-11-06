/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:03:25 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/06 14:53:10 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_op(char *op, t_a *s)
{
	t_o	*new;
	t_o	*tmp;

	new = (t_o*)malloc(sizeof(t_o));
	new->op = ft_strdup(op);
	new->opcode = ret_opcode(op, s);
	new->next = NULL;
	int st_p = s->i;
	while (s->f[s->i] != '\n')
		s->i++;
	new->args = ft_strsub(s->f, st_p, s->i - st_p);
	if (!s->oplist)
		s->oplist = new;
	else
	{
		tmp = s->oplist;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	//парсер аргументів з треканням виклику лейбла
	//arg_pars();
	printf("op |%s| args |%s|\n", op, new->args);
}
