/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:56:04 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/03 19:16:48 by dmaznyts         ###   ########.fr       */
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
	(void)s;
	return (1);
}

int		ch_op(t_a *s)
{
	int		n;
	char	*cmp;

	n = 0;
	while (s->f[s->i] == ' ' || s->f[s->i] == '\t' || s->f[s->i] == '\n')
		s->i++;
	while ((s->f + s->i)[n] != ' ' && (s->f + s->i)[n] != '\t' &&
			(s->f + s->i)[n] != DIRECT_CHAR && (s->f + s->i)[n] != '\0')
		n++;
	cmp = ft_strsub(s->f + s->i, 0, n);
	s->i += n;
	n = 0;
	while (n < 16)
	{
		if (ft_strequ(s->op[n++], cmp))
		{
			//функция пихания в лист операций
			// и считывания аргументов для операции
			//add_op(s->op[n - 1], s);
			printf("operation found |%s|\n", cmp);
			return (1);
		}
	}
	ft_strdel(&cmp);
	return (0);
}

int		check(t_a *s)
{
	//check label
	if (ch_op(s))
		return (1);
	else if (ch_l(s))
		return (1);
	else
		return (0);
}

size_t			ft_bytelen(unsigned char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
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

void	s32(t_a *s)
{
	while (s->f[s->i] == ' ' || s->f[s->i] == '\t')
		s->i++;
}

void	scom(t_a *s)
{
	while (s->f[s->i] != '\n')
		s->i++;
	s->f[s->i] == '\n' ? s->curr_line++ : 0;
}

int		check_name(t_a *s)
{
	if (ft_strnequ(NAME_CMD_STRING, s->f + s->i,
				ft_strlen(NAME_CMD_STRING)))
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
	return (1);
}

int		check_comm(t_a *s)
{
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
	return (1);
}

int		validate(t_a *s)
{
	int j = 0;
	s->i = 0;
	while (s->f[s->i] != '\0')
	{
		s32(s);
//		printf("|%d|%c|		|%d|\n", s->i, s->f[s->i], j);
//		if (j == 30)			//kostil
//			break ;				//kostil
		if (s->f[s->i] == COMMENT_CHAR)
			scom(s);
		else if (s->f[s->i] == '.')
		{
			if (!check_name(s))
				return (0);
			else if (!check_comm(s))
				return (0);
		}
		else if (!check(s))
			return (0);
//		else if (s->f[s->i] == '\n')
//			s->i++ && s->curr_line++;
		//write ft_bytejoin()
		//check instructions && labels
		s->i++;
		j++;
	}
	return (1);
}
