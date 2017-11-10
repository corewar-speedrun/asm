/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:31:19 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/10 18:46:05 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	reg_exp(char *a)
{
	ft_putstr("Expected register, got \"");
	ft_putstr(a);
	ft_putstr("\"\n");
	return (0);
}

int	ind_exp(char *a)
{
	ft_putstr("Expected indirect, got \"");
	ft_putstr(a);
	ft_putstr("\"\n");
	return (0);
}

int	arg_exp(char *a)
{
	ft_putstr("Expected argument, got \"");
	ft_putstr(a);
	ft_putstr("\"\n");
	return (0);
}

int	reg_bad(int got)
{
	ft_putstr("Bad register number, got \"");
	ft_putnbr(got);
	ft_putstr("\", maximum \"");
	ft_putnbr(REG_NUMBER);
	ft_putstr("\"\n");
	return (0);
}
