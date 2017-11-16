/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:00:34 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/15 20:29:30 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ld_er(char *s)
{
	ft_putstr("Label \"");
	ft_putstr(s);
	ft_putstr("\" is not defined!\n");
	return (0);
}

void	print_usage(char *pname)
{
	ft_putstr("Usage: ");
	ft_putstr(pname);
	ft_putstr(" [-a] <sourcefile.s>\n");
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

int		pe(char *s)
{
	ft_putstr(s);
	return (0);
}
