/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:28:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/31 10:55:17 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init(t_a *s)
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
}

void	print_usage(char *pname)
{
	ft_putstr("Usage: ");
	ft_putstr(pname);
	ft_putstr(" [-a] <sourcefile.s>\n");
	ft_putstr("\t-a : Instead of creating a .cor file, outputs a stripped ");
	ft_putstr("and annotated version of the code to the standard output\n");
}

void	cs(char *fn)
{
	ft_putstr("File : ");
	ft_putstr(fn);
	ft_putstr(" \e[1;32m>>>>> Successful! <<<<<\e[0m\n");
}

void	ve(char *fn, char *er)
{
	ft_putstr("File : ");
	ft_putstr(fn);
	ft_putstr(" : \e[1;31mError!\e[0m : ");
	ft_putstr(er);
	ft_putchar('\n');
}

void	putmagic(t_a *s)
{
	union u_onebyte	z;
	char			magic[4];

	(void)s;
	z.magic = COREWAR_EXEC_MAGIC;
	magic[0] = z.bit[3];
	magic[1] = z.bit[2];
	magic[2] = z.bit[1];
	magic[3] = z.bit[0];
	s->output = ft_strdup(magic);
//	write(fd, &z.bit[3], 1);
//	write(fd, &z.bit[2], 1);
//	write(fd, &z.bit[1], 1);
//	write(fd, &z.bit[0], 1);
}

int		split_cnt(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

char	*ft_strndup(char *src)
{
	char	*ret;
	size_t	i;

	i = -1;
	ret = (char*)malloc(sizeof(char) * ft_strlen(src) - 2);
	while (++i < ft_strlen(src) - 1)
		ret[i] = src[i];
	return (ret);
}

int		check_ext(t_a *s)
{
	char	**tm;
	int		cnt;
	int		i;
	int		flag;

	tm = ft_strsplit(s->av, '.');
	cnt = split_cnt(tm);
	if (cnt < 2)
		flag = 0;
	else
		if (ft_strequ(tm[cnt - 1], "s"))
		{
			flag = 1;
			s->basename = ft_strndup(s->av);
		}
		else
			flag = 0;
	i = -1;
	while (++i < cnt)
		ft_strdel(&tm[i]);
	free(tm);
	return (flag);
}

int		read_file(t_a *s)
{
	int		fd;
	int		n;
	char	buf[BUFF_SIZE];
	char	*tmp;

	tmp = NULL;
	fd = open(s->av, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("No such file!\n");
		return (0);
	}
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		if (!s->f)
			s->f = ft_strdup(buf);
		else
		{
			tmp = s->f;
			s->f = ft_strjoin(s->f, buf);
			ft_strdel(&tmp);
		}
	}
	if (n < 0)
	{
		ft_putstr("Can't read file!\n");
		return (0);
	}
	else
		return (1);
}

int		compile(t_a *s)
{
	if (validate(s))
	{
		int fd = open(ft_strjoin(s->basename, "cor"), O_CREAT |
			O_WRONLY | O_TRUNC, 0666);
		putmagic(s);
		ft_putstr_fd("bot name and info", fd);
		return (1);
	}
	else
		return (0);
}

void	main_loop(int ac, char **av)
{
	t_a	st;
	int i;

	init(&st);
	i = 0;
	while (++i < ac)
	{
		st.f = NULL;
		st.av = av[i];
		if (check_ext(&st))
		{
			if (read_file(&st))
				compile(&st) ? cs(av[i]) : ve(av[i], "incorrect file");
			else
				ve(av[i], "file error");
		}
		else
			ve(av[i], "Not '.s' file!");
		ft_bzero(st.prog_name, PROG_NAME_LENGTH + 1);
		ft_bzero(st.comment, COMMENT_LENGTH + 1);
	}
}

int		main(int ac, char **av)
{
	if (ac < 2)
		print_usage(av[0]);
	else
		main_loop(ac, av);
	return (0);
}
