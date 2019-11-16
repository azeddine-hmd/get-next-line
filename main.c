#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	char	*line;
	int		fd;
	int		r;

	fd = open("main.c", O_RDONLY);
	printf("\033[0;32m<======[main.c]======>\033[0m\n");
	while ((r = get_next_line(fd, &line)))
	{
		printf("%d|%s\n", r, line);
		free(line);
	}
	printf("%d|%s\n", r, line);
	free(line);

	close(fd);
	return (0);
}
