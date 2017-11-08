/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:00:59 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/08 11:40:19 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	p_live(char *a)
{
	int	i;

	i = 0;
	while (a[i] == ' ' || a[i] == '\t')
		i++;
	if (a[i] != DIRECT_CHAR)
		return (dir_exp(a[i]));
	else
	{
		if (a[++i] == LABEL_CHAR)
			
	}
}

int	p_ld(char *a)
{
	
}

int	p_st(char *a)
{
	
}

int	p_add(char *a)
{
	
}

int	p_sub(char *a)
{

}

int	p_and(char *a)
{

}

int	p_or(char *a)
{
	
}

int	p_xor(char *a)
{

}

int	p_zjmp(char *a)
{

}

int	p_ldi(char *a)
{

}

int	p_sti(char *a)
{

}

int	p_fork(char *a)
{

}

int	p_lld(char *a)
{

}

int	p_lldi(char *a)
{

}

int	p_lfork(char *a)
{

}

int	p_aff(char *a)
{

}
