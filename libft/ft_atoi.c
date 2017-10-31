/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:59:18 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/10/04 16:20:47 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int min;

	i = 0;
	n = 0;
	min = 1;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)) && str[i] != '\0')
	{
		if (str[i] == '\200')
			return (0);
		i++;
	}
	if (str[i] == '-')
		min = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		n *= 10;
		n += ((int)str[i] - 48);
		i++;
	}
	return (n * min);
}
