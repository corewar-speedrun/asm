/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:56:04 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/30 17:36:54 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_le(int i, t_a *s)
{
	ft_putstr("Lexical error at [");
	ft_putnbr(s->curr_line);
	ft_putchar(':');
	ft_putnbr(i);
	ft_putstr("]\n");
}

int		grep_name(t_a *s)
{
	int name_point_stop = 0;
	int name_point_start = 0;
	int tmp_i = 1;
	while (s->f[s->i] == NAME_CMD_STRING[tmp_i - 1])
		s->i++ && tmp_i++;
	while ((s->f[s->i] == ' ' || s->f[s->i] == '\t') &&
			(s->f[s->i] != '\"' && s->f[s->i] != '\n'))
		s->i++ && tmp_i++;
	if (s->f[s->i] != '\"')
	{
		print_le(tmp_i, s);
		return (0);
	}
	name_point_start = s->i++;
	while (s->f[s->i] != '\"')
		s->i++ && tmp_i++;
	name_point_stop = s->i++;
	while (s->f[s->i] != '\n')
	{
		if (s->f[s->i] != ' ' && s->f[s->i] != '\t' && s->f[s->i] != '\n')
		{
			print_le(tmp_i, s);
			return (0);
		}
		s->i++ && tmp_i++;
	}
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
	while (s->f[s->i] != '\"')
		s->i++;
	comment_point_start = s->i++;
	while (s->f[s->i] != '\"')
		s->i++;
	comment_point_stop = s->i;
	s->comment_tmp = ft_strsub(s->f, comment_point_start,
			comment_point_stop - comment_point_start);
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

int		validate(t_a *s)
{
	s->i = 0;
	while (s->f[s->i] != '\0')
	{
		while (s->f[s->i] == ' ' || s->f[s->i] == '\t')
			s->i++;
		if (s->f[s->i] == COMMENT_CHAR)
			while (s->f[s->i] != '\n')
				s->i++;
		s->f[s->i] == '\n' ? s->curr_line++ : 0;
		if (ft_strnequ(NAME_CMD_STRING, s->f + s->i, ft_strlen(NAME_CMD_STRING)))
		{
			if (s->prog_name[0] == '\0')
			{
				if (grep_name(s) == 0)
					return (0);
			}
			else
			{
				ft_putstr("Duplicate .name in file\n");
				return (0);
			}
		}
		if (ft_strnequ(COMMENT_CMD_STRING, s->f + s->i,
					ft_strlen(COMMENT_CMD_STRING)))
		{
			if (s->comment[0] == '\0')
			{
				if (grep_comm(s) == 0)
					return (0);
			}
			else
			{
				ft_putstr("Duplicate .comment in file");
				return (0);
			}
		}
		//check instructions && labels
		s->i++;
	}
	return (1);
}
