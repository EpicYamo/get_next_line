#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int i = 0;
	int fd = open("text.txt", O_RDWR);
	int fd2 = open("text2.txt", O_RDWR);
	char *a;
	char *b;
	while (i < 8)
	{
		a = get_next_line(fd);
		b = get_next_line(fd2);
		printf("%s", a);
		printf("%s", b);
		free(a);
		free(b);
		i++;
	}
}
