/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:07:45 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/04 11:53:21 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t			ft_bytelen(unsigned char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

unsigned char	ret_opcode(char *op, t_a *s)
{
	unsigned char	opcode;
	int				i;

	i = -1;
	while (++i < 16)
		ft_strequ(op, s->op[i]) ? opcode = i + 1 : 0;
	return (opcode);
}

unsigned char	*ft_bytejoin(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*ret;
	size_t			i;
	size_t			j;

	if (!s1 || !s2)
		return (NULL);
	ret = (unsigned char*)malloc(ft_bytelen(s1) + ft_bytelen(s2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		ret[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
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
	s->total_bytes = 0;
	s->oplist = NULL;
	s->lablist = NULL;
}
