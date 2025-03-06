int	main(int argc, char **argv)
{
	char *line;
	int	i;
	int	fd;

	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1);
		line = get_next_line(fd);
		if (!line)
			return (close(fd), 0);
		while (line)
		{
			printf("%d : %s\n", i++, line);
			free(line);
			line = NULL;
			line = get_next_line(fd);
		}
		printf("%d : %s\n", i, line);
		free(line);
		close(fd);
	}
	printf("\n");
	return (0);
}
