#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/* 
ft_free_str
strdup
strchr
substr
strlen
strjoin_gnl
*/

char	*get_next_line(fd)
{

}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
		line = get_next_line(fd);
		if (!line)
			printf("(NULL)");
		while (line)
		{
			printf("%d	-->	%s\n", i++, line);
			free(line);
			line = NULL;
			line = get_next_line(fd);
		}
		printf("%d	-->	%s\n", i, line);
		free(line);
		line = NULL;
	}
	printf("\n");
	return (0);
}
