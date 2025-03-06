#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
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
		dst[i] = src[i];
		i++;
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
	return (ft_free_str(&s1), NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (ft_free_str(&s1), s3);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

char	*add_buffer(int fd, char *buff)
{
	ssize_t		bytes_read;
	char		*add_buff;

	add_buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!add_buff)
		return (NULL);
	bytes_read = 1;
	add_buff[0] = '\0';
	while (!ft_strchr(add_buff, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, add_buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free_str(&add_buff);
			ft_free_str(&buff);
			return (NULL);
		}
		add_buff[bytes_read] = '\0';
		if (bytes_read > 0)
			buff = ft_strjoin(buff, add_buff);
	}
	ft_free_str(&add_buff);
	return (buff);
}

char	*get_line(char *buffer, char **line)
{
	char	*rest;
	int		l_buff;

	rest = NULL;
	l_buff = ft_strlen(buffer);
	if (!buffer || !line)
		return (NULL);
	if (ft_strchr(buffer, '\n'))
	{
		rest = ft_strdup(ft_strchr(buffer, '\n') + 1);
		*line = ft_substr(buffer, 0, l_buff - ft_strlen(rest));
	}
	else
	{
		*line = ft_substr(buffer, 0, l_buff);
	}
	ft_free_str(&buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer || !ft_strchr(buffer, '\n'))
		buffer = add_buffer(buffer, fd);
		if (!buffer)
			return (NULL);
	return (get_line(buffer, &line));
}
