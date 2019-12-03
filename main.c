#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	argc = 2;
	int a = get_next_line(argc, argv);
	printf("%d\n", a);
	return (0);
}