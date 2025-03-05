#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef	BUFFER_SIZE
# define	BUFFER_SIZE 42
#endif

void	ft_free_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!dst || !src)
		return ;
	while (len > 0 && src[i])
	{
		dst[i] = src[i++];
		len--;
	}
	dst[i] = '\0';
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	if (!str)
	return (NULL);
	i = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, str, i);
	return (dup);
}

char	*ft_substr(char *str, int start, int len)
{
	int		i;
	char	*sub;

	if (len <= 0)
	return (NULL);
	if (start < 0)
		return (NULL);
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (NULL);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (str[start] && len--)
		sub[i++] = str[start++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *dst, char* src)
{
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
			return ((char *)&str[i++]);
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (0);
}
char	*get_line(char *buffer)
{}

char	*add_buffer(char *buffer, int fd)
{
	char	*addbuff;
	ssize_t	b_size;

	addbuff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!addbuff)
		return (ft_free_str(&buffer), NULL);
	b_size = 1;
	while (b_size > 0 && !ft_strchr(buffer, '\n'))
	{
		b_size = read(fd, addbuff, BUFFER_SIZE);
		if (b_size < 0)
			return (ft_free_str(&buffer),ft_free_str(&addbuff), NULL);
		addbuff[b_size] = '\0';
		if (!buffer && b_size > 0)
		buffer = ft_strdup(addbuff);
		else if (b_size > 0)
		buffer = ft_strjoin(buffer, addbuff);
	}
	return (ft_free_str(&addbuff), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || !ft_strchr(buffer, '\n'))
		buffer = add_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	return (get_line(buffer));
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

/*
 ->VARIABLE char static *buffer

si no hay texto o archivo o no hay tamaño de lectura
	return ()
si no hay linea anterior(static) o no hay salto de linea en la static
	añadir buffer en buffer

	*añadir buffer(* buffer)
	{
		reservar memoria malloc(buffersize + 1)
		si no funciona
			return liberar estatica!!
		forzamos bytes leidos a 1 para el while
		el while (b_size > 0 && no hay salto de linea en estatica)
			b_read = read(fd, addbuff, buffer_size)
		  //bytes leidos = read(que leo, donde lo guardo, cuanto leo)
		si no hay lectura(b_read < 0)
			return (ft_free_str(buffer), ft_free_str(addbuff), NULL)
		adbbuff[b_read] = '\0';
		si hay lectura(b_read < 0)
			buffer = strjoin(buffer, addbuff);
	}
comprobar !buffer)

sacar lineas
return linea)
*/