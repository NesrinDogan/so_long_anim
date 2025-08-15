#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *s;

	fd = open("maps/map.ber", O_RDONLY);
	s = get_next_line(fd);

	while (s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
	free(s);


	return (0);
}
