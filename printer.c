/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:31:28 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/09 15:38:13 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	dir_exp(char a)
{
	ft_putstr("Expected ");
	ft_putchar(DIRECT_CHAR);
	ft_putstr(", got \"");
	if (a == '\n')
		ft_putstr("newline break");
	else
		ft_putchar(a);
	ft_putstr("\"\n");
	return (0);
}

int	nc_exp(char a)
{
	ft_putstr("Expected newline break or ");
	ft_putchar(COMMENT_CHAR);
	ft_putstr(", got \"");
	ft_putchar(a);
	ft_putstr("\"\n");
	return (0);
}

int	num_exp(char a)
{
	ft_putstr("Expected number, got \"");
	ft_putchar(a);
	ft_putstr("\"\n");
	return (0);
}

int	er_stru(void)
{
	ft_putstr("File should end with newline, but NULL-Terminator found\n");
	return (0);
}
