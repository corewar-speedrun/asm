#include "asm.h"
#include <stdio.h>

int main()
{
/*	t_header	test;

	test.magic = COREWAR_EXEC_MAGIC;
	test.prog_name[0] = '4';
	test.prog_name[1] = '2';
	test.prog_size = 42;
	test.comment[0] = '4';
	test.comment[1] = '2';
	int fd = open("test.out", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	write(fd, &test, sizeof(test));*/

	short int a;

	a = -5;
	printf("%.2x\n", a);
	return (0);
}
