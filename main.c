#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	char	*line;
	int		fd;

	// openning file descrioptor
	fd = open("res.txt", O_RDONLY);

	//testing
	get_next_line(fd, &line);
	printf("line[0]='%s'\n", line);
	get_next_line(fd, &line);
	printf("line[0]='%s'\n", line);
	get_next_line(fd, &line);
	printf("line[0]='%s'\n", line);
	get_next_line(fd, &line);
	printf("line[0]='%s'\n", line);
	get_next_line(fd, &line);
	printf("line[0]='%s'\n", line);
	get_next_line(fd, &line);
	printf("line[0]='%s'\n", line);
	get_next_line(fd, &line);
	printf("line[0]='%s'\n", line);


	// closing file descriptor
	close(fd);
}
