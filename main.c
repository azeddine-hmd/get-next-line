#include "get_next_line.h"

int		main(void)
{
	char	*line;
	int		fd;
	int i = 0;

	// openning file descrioptor
	fd = open("res.txt", O_RDONLY);

	//testing
	while ((i = get_next_line(fd, &line)))
	{
		printf("%d* %s\n",i, line);
		free(line);
	}
		printf("%d* %s\n",i, line);
		free(line);
	// closing file descriptor
	close(fd);
}
