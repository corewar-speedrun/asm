/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:03:25 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/04 12:08:56 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_op(char *op, t_a *s)
{
	t_o	*new;

	new = (t_o*)malloc(sizeof(t_o));
	new->op = ft_strdup(op);
	new->opcode = ret_opcode(op, s);
	int st_p = s->i;
	while (s->f[s->i] != '\n')
		s->i++;
	new->args = ft_strsub(s->f, st_p, s->i - st_p);
	printf("op |%s| args |%s|\n", op, new->args);
}
