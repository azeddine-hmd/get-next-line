#include "get_next_line.h"
#define FILE1 "res1.txt"
#define FILE2 "res2.txt"
#define FILE3 "res3.txt"

int		main(void)
{
	char	*line;
	int	fd;
	int	i = 0;

	// openning file descrioptor
	fd = open(FILE1, O_RDONLY);

	//testing1
	while ((i = get_next_line(fd, &line)))
	{
		printf("%d* %s\n",i, line);
		free(line);
	}
	printf("%d* %s\n",i, line);
	free(line);
	
	fd = open(FILE2, O_RDONLY);
	//testing2
	while ((i = get_next_line(fd, &line)))
	{
		printf("%d* %s\n",i, line);
		free(line);
	}
	printf("%d* %s\n",i, line);
	free(line);

	fd = open(FILE3, O_RDONLY);

	//testing3
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
