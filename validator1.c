/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:56:04 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 21:00:37 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		grep_name(t_a *s)
{
	int name_point_stop = 0;
	int name_point_start = 0;
	int tmp_i = 0;

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
	name_point_start = s->i++;
	while (s->f[s->i] != '\"')
	{
		s->i++;
		tmp_i++;
	}
	name_point_stop = s->i++;
	while (s->f[s->i] != '\n')
	{
		if (s->f[s->i] != ' ' && s->f[s->i] != '\t' && s->f[s->i] != '\n')
		{
			print_le(tmp_i, s);
			return (0);
		}
		s->i++;
		tmp_i++;
	}
	s->i++;
	s->curr_line++;
	s->prog_name_tmp = ft_strsub(s->f, name_point_start,
			name_point_stop - name_point_start);
	if (ft_strlen(s->prog_name_tmp) > PROG_NAME_LENGTH)
	{
		ft_putstr("Champion name is too long (Max ");
		ft_putnbr(PROG_NAME_LENGTH);
		ft_putstr(" ASCII chars)\n");
		return (0);
	}
	else
		ft_strcpy(s->prog_name, s->prog_name_tmp);
	return (1);
}

int		grep_comm(t_a *s)
{
	int comment_point_start = 0;
	int comment_point_stop = 0;
	int tmp_i = 0;

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
	if (s->f[s->i] != '\"')
	{
		print_le(tmp_i, s);
		return (0);
	}
	comment_point_start = s->i++;
	while (s->f[s->i] != '\"' && s->f[s->i] != '\0')
	{
		s->i++;
		tmp_i++;
	}
	comment_point_stop = s->i++;
	while (s->f[s->i] != '\n')
	{
		if (s->f[s->i] != ' ' && s->f[s->i] != '\t' && s->f[s->i] != '\n')
		{
			print_le(tmp_i, s);
			return (0);
		}
		s->i++;
		tmp_i++;
	}
	if (s->f[s->i] == '\0')
	{
		ft_putstr("expected '\"' for comment. File with no operations");
		return (0);
	}
	s->comment_tmp = ft_strsub(s->f, comment_point_start,
			comment_point_stop - comment_point_start);
	s->i++;
	if (ft_strlen(s->comment_tmp) > COMMENT_LENGTH)
	{
		ft_putstr("Champion comment is too long (Max ");
		ft_putnbr(COMMENT_LENGTH);
		ft_putstr(" ASCII chars)\n");
		return (0);
	}
	else
		ft_strcpy(s->comment, s->comment_tmp);
	return (1);
}

int		ch_l(t_a *s)
{
	size_t	n;
	char	*cmp;

	n = 0;
	while (s->f[s->i] == ' ' || s->f[s->i] == '\t' || s->f[s->i] == '\n')
		s->i++;
	while ((s->f + s->i)[n] != ' ' && (s->f + s->i)[n] != '\t' &&
			(s->f + s->i)[n] != '\0')
		n++;
	cmp = ft_strsub(s->f + s->i, 0, n);
	s->i += n;
	n = 0;
	if (cmp[ft_strlen(cmp) - 1] != LABEL_CHAR)
		return (1);
	while (n < ft_strlen(cmp))
	{
		if (!ft_strchr(LABEL_CHARS, cmp[n]))
		{
			ft_putstr(cmp);
			ft_putstr("Illegal label char at line ");
			ft_putnbr(s->curr_line);
			ft_putchar('\n');
			return (0);
		}
		add_la(cmp, s);
		return (1);
	}
	ft_strdel(&cmp);
	return (0);
}

int		ch_op(t_a *s)
{
	int		n;
	char	*cmp;

	n = 0;
	s32(s);
	while ((s->f + s->i)[n] != ' ' && (s->f + s->i)[n] != '\t' &&
			(s->f + s->i)[n] != COMMENT_CHAR && (s->f + s->i)[n] != '\n'
			&& (s->f + s->i)[n] != ';')
		n++;
	cmp = ft_strsub(s->f, s->i, n);
	if (cmp[ft_strlen(cmp) - 1] == LABEL_CHAR)
	{
		add_la(cmp, s);
		s->i += n;
		return (1);
	}
	s->i += n;
	n = 0;
	while (n < 16)
	{
		if (ft_strequ(s->op[n++], cmp))
		{
			if (add_op(s->op[n - 1], s))
				return (1);
			else
				return (0);
		}
	}
	ft_strdel(&cmp);
	return (0);
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
			if (!check_name(s))
				return (0);
			else if (!check_comm(s))
				return (0);
		}
		else if (s->f[s->i] == '\n')
			s->i++ && s->curr_line++;
		else if (!check(s))
			return (0);
		j++;
	}
	return (ass_lab(s));
}
