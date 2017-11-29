/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:56:04 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/29 03:03:36 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		grep_name(t_a *s, int stop, int start, int tmp_i)
{
	while (s->f[s->i] == NAME_CMD_STRING[tmp_i])
	{
		s->i++;
		tmp_i++;
	}
	while ((s->f[s->i] == ' ' || s->f[s->i] == '\t') &&
			(s->f[s->i] != '\"' && s->f[s->i] != '\n'))
	{
		s->i++;
		tmp_i++;
	}
	if (s->f[s->i] != '\"')
	{
		print_le(tmp_i, s);
		return (0);
	}
	if (!grep_name2(s, &stop, &start, &tmp_i))
		return (0);
	s->prog_name_tmp = ft_strsub(s->f, start, stop - start);
	if (ft_strlen(s->prog_name_tmp) >= PROG_NAME_LENGTH)
		return (lcnd());
	else
		ft_strcpy(s->prog_name, s->prog_name_tmp);
	return (1);
}

int		grep_comm(t_a *s, int start, int stop, int tmp_i)
{
	while (s->f[s->i] == COMMENT_CMD_STRING[tmp_i])
	{
		s->i++;
		tmp_i++;
	}
	while ((s->f[s->i] == ' ' || s->f[s->i] == '\t') &&
			(s->f[s->i] != '\"' && s->f[s->i] != '\n'))
	{
		s->i++;
		tmp_i++;
	}
	if (!grep_comm2(s, &start, &stop, &tmp_i))
		return (0);
	s->comment_tmp = ft_strsub(s->f, start, stop - start);
	if (ft_strlen(s->comment_tmp) > COMMENT_LENGTH)
		return (lccd());
	else
		ft_strcpy(s->comment, s->comment_tmp);
	return (1);
}

int		extra(char *s, int i)
{
	while (s[i] != '\n' && s[i] != '\0')
	{
		if (ft_isalnum(s[i]) && s[i + 1] == LABEL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

int		ch_op(t_a *s)
{
	int		n;
	char	*cmp;
	int		flag;

	flag = 0;
	n = 0;
	s32(s);
	while ((s->f + s->i)[n] != ' ' && (s->f + s->i)[n] != '\t' &&
			(s->f + s->i)[n] != COMMENT_CHAR && (s->f + s->i)[n] != '\n'
			&& (s->f + s->i)[n] != ';' && s->f[s->i + n] != LABEL_CHAR
			&& s->f[s->i + n])
		n++;
	s->f[s->i + n] == LABEL_CHAR ? (n++) : 0;
	cmp = ft_strsub(s->f, s->i, n);
	if (normefucker5(cmp, &flag, n, s))
		return (flag);
	s->i += n;
	n = 0;
	while (n < 16)
		if (ft_strequ(s->op[n++], cmp))
			if (add_op(s->op[n - 1], s))
				flag = 1;
	ft_strdel(&cmp);
	return (flag);
}

int		validate(t_a *s)
{
	int j;

	j = 0;
	s->i = 0;
	while (s->f[s->i] != '\0')
	{
		s32(s);
		if (s->f[s->i] == COMMENT_CHAR || s->f[s->i] == ';')
			scom(s);
		else if (s->f[s->i] == '.')
		{
			if (!ch_naco(s))
				return (0);
		}
		else if (s->f[s->i] == '\n')
			s->i++ && s->curr_line++;
		else if (!check(s))
			return (0);
		s32(s);
		j++;
	}
	return (ass_lab(s));
}
