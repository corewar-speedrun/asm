/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:53:09 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 20:54:46 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		print_uc(t_a *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s->f[s->i + i] != ' ' && s->f[s->i + i] != '\t'
		&& s->f[s->i + i] != '\n' && s->f[s->i + i] != '\0')
		i++;
	tmp = ft_strsub(s->f, s->i, i);
	ft_putstr("Unknown command \"");
	ft_putstr(tmp);
	ft_strdel(&tmp);
	ft_putstr("\".\n");
	return (0);
}

int		ch_naco(t_a *s)
{
	if (ft_strnequ(NAME_CMD_STRING, s->f + s->i,
				ft_strlen(NAME_CMD_STRING)))
	{
		if (s->prog_name[0] == '\0')
		{
			if (grep_name(s, 0, 0, 0) == 0)
				return (0);
		}
		else
			return (pe("Duplicate .comment in file\n"));
	}
	else if (ft_strnequ(COMMENT_CMD_STRING, s->f + s->i,
				ft_strlen(COMMENT_CMD_STRING)))
	{
		if (s->comment[0] == '\0')
		{
			if (grep_comm(s, 0, 0, 0) == 0)
				return (0);
		}
		else
			return (pe("Duplicate .comment in file\n"));
	}
	else
		return (print_uc(s));
	return (1);
}
