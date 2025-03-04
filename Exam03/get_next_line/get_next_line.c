#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef
# define	BUFFER_SIZE
#endif

void	ft_free_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}
char	*ft_strjoin(char *dst, char* src)
{
	int	i;

	i = 0;
	if (!dst)
	{
		dst[i] = src[i];
	}
	while (dst && src)
	{
	}
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (0);
}

char	*add_buffer(char **buffer, int fd)
{
	char	*addbuff;
	ssize_t	b_size;

	addbuff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)
	if (!addbuff)
		return (ft_free_str(&buffer), NULL);
	b_size = 1;
	while (b_size > 0 || ft_strchr(*buffer, '\n'))
	{
		b_size = read(fd, addbuff, BUFFER_SIZE);
		if (b_size < 0)
			return (ft_free_str(&buffer),ft_free_str(&addbuff), NULL);
		addbuff[b_size] = '\0';
		*buffer = ft_strjoin(*buffer, addbuff);

	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || !ft_strchr(buffer, '\n'))
		buffer = add_buffer(&buffer, fd);
	if (!buffer)
		return (NULL);
}

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
