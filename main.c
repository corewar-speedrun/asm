/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:28:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/14 21:18:03 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	ft_putstr(" : \e[1;31mError!\e[0m ");
	ft_putstr(er);
	ft_putchar('\n');
}

void	putmagic(t_a *s)
{
	union u_onebyte	z;

	z.magic = COREWAR_EXEC_MAGIC;
	add_code_h(z.bit[0], s);
	add_code_h(z.bit[1], s);
	add_code_h(z.bit[2], s);
	add_code_h(z.bit[3], s);
}

void	putname(t_a *s)
{
    int	l2;
	int	len;

	len = PROG_NAME_LENGTH + 1;
	l2 = ft_strlen(s->prog_name);
	while (len > 0)
	{
		if (s->prog_name[len] != 0 && len <= l2)
		{
			add_code_h(s->prog_name[len], s);
			l2--;
		}
		else
			add_code_h(0, s);
		len--;
	}
}

void	putcomment(t_a *s)
{
	int	len;
	int	l2;

	l2 = ft_strlen(s->comment);
	len = COMMENT_LENGTH + 1;
	while (len > 0)
	{
		if (s->comment[len] != 0 && len <= l2)
		{
			add_code_h(s->comment[len], s);
			l2--;
		}
		else
			add_code_h(0, s);
		len--;
	}
}

void	putident(t_a *s)
{
	int id;

	id = 0;
	if ((PROG_NAME_LENGTH + 1) % 4 != 0)
		id = 4 - (PROG_NAME_LENGTH + 1) % 4;
	while (id-- > 0)
		add_code_h(0, s);
}

void	putsize(t_a *s)
{
	union u_onebyte	z;

	z.magic = s->total_bytes;
	add_code_h(z.bit[0], s);
	add_code_h(z.bit[1], s);
	add_code_h(z.bit[2], s);
	add_code_h(z.bit[3], s);
}

char	*ft_strndup(char *src)
{
	char	*ret;
	size_t	i;

	i = -1;
	ret = (char*)malloc(sizeof(char) * ft_strlen(src) - 1);
	ft_bzero(ret, ft_strlen(src) - 1);
	while (++i < ft_strlen(src) - 1)
		ret[i] = src[i];
	return (ret);
}

int		check_ext(t_a *s)
{
	int		flag;

	if (ft_strequ(s->av + (ft_strlen(s->av) - 2), ".s"))
	{
		flag = 1;
		s->basename = ft_strndup(s->av);
	}
	else
		flag = 0;
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
			free(tmp);
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

int		writeout_fd(t_a *s, int fd)
{
	int		i;
	t_pro	*tmp;

	tmp = s->output;
	i = -1;
	if (fd < 3)
	{
		ft_putstr("Impossible to write to file! I/O/E stream detected\n");
		return (0);
	}
	while (tmp)
	{
		write(fd, &tmp->byte, 1);
		tmp = tmp->next;
	}
	return (1);
}

void	add_code_h(unsigned char cod, t_a *s)
{
	t_pro	*new;
	
	new = (t_pro*)malloc(sizeof(t_pro));
	new->byte = cod;
	new->nb = s->total_bytes;
	new->next = s->output;
	s->output = new;
}

int		compile(t_a *s)
{
	int	fd;
	int	flag;

	fd = open(ft_strjoin(s->basename, "cor"), O_CREAT | O_WRONLY |
			O_TRUNC, 0666);
	if (s->f[ft_strlen(s->f) - 1] != '\n')
		return (er_stru());
	if (validate(s))
	{
		putident(s);
		putcomment(s);
		putsize(s);
		putident(s);
		putname(s);
		putmagic(s);
		flag = writeout_fd(s, fd);
		return (flag);
	}
	else
		return (0);
}

void	main_loop(int ac, char **av)
{
	t_a	st;
	int i;

	init(&st);
	init2(&st);
	i = 0;
	while (++i < ac)
	{
		st.f = NULL;
		st.av = av[i];
		if (check_ext(&st))
		{
			if (read_file(&st))
				compile(&st) ? cs(av[i]) : ve(av[i], "");
			else
				ve(av[i], "file error");
		}
		else
			ve(av[i], "Not '.s' file!");
		ft_bzero(st.prog_name, PROG_NAME_LENGTH + 1);
		ft_bzero(st.comment, COMMENT_LENGTH + 1);
		ft_strdel(&st.f);
	}
}

int		main(int ac, char **av)
{
	if (ac < 2 && ac > 0)
		print_usage(av[0]);
	else
		main_loop(ac, av);
	LEAK
	return (0);
}
