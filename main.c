/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:28:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/20 09:08:11 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		read_file(t_a *s)
{
	int		fd;
	int		n;
	char	buf[BUFF_SIZE];
	char	*tmp;

	tmp = NULL;
	fd = open(s->av, O_RDONLY);
	if (fd < 0)
		return (pe("No such file!\n"));
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		if (!s->f)
			s->f = ft_strdup(buf);
		else
			s->f = joincasino(s->f, buf);
	}
	if (!s->f || (!ft_isprint(s->f[0]) && !ft_isprint(s->f[1])))
		return (pe("Empty or binary file\n"));
	if (n < 0)
		return (pe("Can't read file!\n"));
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

int		compile(t_a *s)
{
	int		fd;
	int		flag;
	char	*t;

	flag = 1;
	t = ft_strjoin(s->basename, "cor");
	(last(s->f, 0, 0) == 1) ? (flag = er_stru()) : 0;
	!validate(s) ? (flag = 0) : 0;
	if (flag)
	{
		putident(s);
		putcomment(s);
		putsize(s);
		putident(s);
		putname(s);
		putmagic(s);
		fd = open(t, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		flag = writeout_fd(s, fd);
	}
	ft_strdel(&t);
	return (flag);
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
		freeall(&st);
	}
	freeall(&st);
	st.op ? (freeop(st.op)) : 0;
}

int		main(int ac, char **av)
{
	if (ac < 2 && ac > 0)
		print_usage(av[0]);
	else
		main_loop(ac, av);
	return (0);
}
