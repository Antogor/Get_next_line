#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main()
{
	char *a;
	int fd1;
	int fd2;
	int b;

	fd1 = open("leer.txt", O_RDONLY);
	fd2 = open("leer2.txt", O_RDONLY);
	b = get_next_line(fd1, &a);
	printf("%s %d\n", a, b);
	b = get_next_line(fd1, &a);
	b = get_next_line(fd2, &a);
	printf("%s %d\n", a, b);
	b = get_next_line(fd1, &a);
	printf("%s %d\n", a, b);
	b = get_next_line(fd2, &a);
	printf("%s %d\n", a, b);
	b = get_next_line(fd2, &a);
	printf("%s %d\n", a, b);
	close(fd1);
	close(fd2);
	return (0);
}