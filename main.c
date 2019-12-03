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
	int fd3;

	fd1 = open("leer.txt", O_RDONLY);
	printf("%d,\n", fd1);
	fd2 = open("leer2.txt", O_RDONLY);
	printf("%d,\n", fd2);
	fd3 = open("leer2.txt", O_RDONLY);
	printf("%d,\n", fd3);
	get_next_line(fd1, &a);
	printf("%s\n", a);
	close(fd1);
	//get_next_line(fd2, &a);
	//printf("%s\n", a);
	//close(fd2);
	return (0);
}