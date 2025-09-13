#include <unistd.h>
#include <stdlib.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))     // verificación de argumentos
		return (-1);

	int fd[2];

	pipe(fd);
	if (type == 'r') // si es read, devuelvo lectura
	{
		if (fork() == 0)
		{
			dup2(fd[1], STDOUT_FILENO); // el hijo redirige stdout al pipe. (redirige salida al pipe de escritura)
			close(fd[0]);
			close(fd[1]);
			execvp(file, argv); // hijo ejecuta el comando
			exit(-1);
		}
		close(fd[1]); // padre cierra escritura
		return (fd[0]); // devuelve lectura
	}
	if (type == 'w') // si es write, devuelvo escritura
	{
		if (fork() == 0)
		{
			dup2(fd[0], STDIN_FILENO); // (redirige entrada al pipe de lectura)
			close(fd[1]);
			close(fd[0]);
			execvp(file, argv);
			exit(-1);
		}
		close(fd[0]);
		return (fd[1]);
	}
	return (-1);
}
