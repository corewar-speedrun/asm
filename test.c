/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:52:51 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/04 16:54:43 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int main()
{
	t_header	test;

	test.magic = COREWAR_EXEC_MAGIC;
	test.prog_name[0] = '4';
	test.prog_name[1] = '2';
	test.prog_size = 42;
	test.comment[0] = '4';
	test.comment[1] = '2';
	int fd = open("test.out", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	write(fd, &test, sizeof(test));
	return (0);
}
