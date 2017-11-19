/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 12:04:32 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/19 12:04:46 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		pe(char *s)
{
	ft_putstr(s);
	return (0);
}

int		emplabdef(void)
{
	ft_putstr("Empty label defined!\n");
	return (0);
}

int		emplabcal(void)
{
	ft_putstr("Empty label called!\n");
	return (0);
}

int		lccd(void)
{
	ft_putstr("Champion comment is too long (Max ");
	ft_putnbr(COMMENT_LENGTH);
	ft_putstr(" ASCII chars)\n");
	return (0);
}
