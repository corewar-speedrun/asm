/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:07:45 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/29 04:38:51 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned char	ret_opcode(char *op, t_a *s)
{
	unsigned char	opcode;
	int				i;

	i = -1;
	while (++i < 16)
		ft_strequ(op, s->op[i]) ? opcode = i + 1 : 0;
	return (opcode);
}

void			init2(t_a *s)
{
	s->op = (char**)malloc(sizeof(char*) * 16);
	s->op[0] = ft_strdup("live");
	s->op[1] = ft_strdup("ld");
	s->op[2] = ft_strdup("st");
	s->op[3] = ft_strdup("add");
	s->op[4] = ft_strdup("sub");
	s->op[5] = ft_strdup("and");
	s->op[6] = ft_strdup("or");
	s->op[7] = ft_strdup("xor");
	s->op[8] = ft_strdup("zjmp");
	s->op[9] = ft_strdup("ldi");
	s->op[10] = ft_strdup("sti");
	s->op[11] = ft_strdup("fork");
	s->op[12] = ft_strdup("lld");
	s->op[13] = ft_strdup("lldi");
	s->op[14] = ft_strdup("lfork");
	s->op[15] = ft_strdup("aff");
}

void			init(t_a *s)
{
	s->f = NULL;
	s->av = NULL;
	s->basename = NULL;
	s->prog_size = 0;
	ft_bzero(s->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(s->comment, COMMENT_LENGTH + 1);
	s->prog_name_tmp = NULL;
	s->comment_tmp = NULL;
	s->curr_line = 1;
	s->i = 0;
	s->output = NULL;
	s->total_bytes = 0;
	s->lablist = NULL;
	s->lcallist = NULL;
	s->args = NULL;
	s->nameflag = 0;
	s->commflag = 0;
}

int				vopros(int j, t_pro *t)
{
	if (j == 2)
	{
		if (t->byte == 0)
			if (t->next->byte == 0)
				return (1);
	}
	else
	{
		if (t->byte == 0)
			if (t->next->byte == 0)
				if (t->next->next->byte == 0)
					if (t->next->next->next->byte == 0)
						return (1);
	}
	return (0);
}

int				grep_name2(t_a *s, int *stop, int *start, int *tmp_i)
{
	*start = s->i++;
	while (s->f[s->i] != '\"')
	{
		s->i++;
		*tmp_i += 1;
	}
	*stop = s->i++;
	while (s->f[s->i] != '\n' && s->f[s->i] != COMMENT_CHAR
			&& s->f[s->i] != ';' && s->f[s->i] != '\0')
	{
		if (s->f[s->i] != ' ' && s->f[s->i] != '\t' && s->f[s->i] != '\n'
			&& s->f[s->i] != COMMENT_CHAR && s->f[s->i] != ';')
		{
			print_le(*tmp_i, s);
			return (0);
		}
		s->i++;
		*tmp_i += 1;
	}
	s->curr_line++;
	return (1);
}
