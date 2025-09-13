#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	pid_t pid;
	int pipefd[2];		// pipe creado para conectar comandos
	int prev_fd = -1;	// fd del pipe anterior (stdin actual)
	int status;			// valos devuelto por wait
	int exit_code = 0;	//codigo de salida (1 si algun hijo termina != 0)
	int i = 0;
	// while por cada comando que existe en nuestro ***array
	while (cmds[i])
	{
		//si sí hay siguiente comando, evalua pipe() == -1
		//(si no hay comando siguiente no crea pipe)
		if (cmds[i + 1] && pipe(pipefd))
			return (1);
		//se crea proceso hijo
		pid = fork();
		//error, cerrar fds
		if (pid == -1)
		{
			//cerrar pipefd completo si hay siguiente comando y salir
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			return (1);
		}
		if (pid == 0)// proceso hijo
		{
			if (prev_fd != -1)
			{
				//redirige stdin
				if (dup2(prev_fd, STDIN_FILENO) == -1)
					exit(1);
				//cierra prev_fd
				close(prev_fd);
			}
			if (cmds[i + 1]) // si hay siguiente comando
			{
				//cierra pipe de lectura
				close(pipefd[0]);
				//redirige stdout a pipe de escritura
				//comando anterior pone su salida stdout en fd[1]
				if (dup2(pipefd[1], STDOUT_FILENO) == -1)
					exit(1); // exit si falla, sale del hijo
				//cierra pipefd de escritura
				close(pipefd[1]);
			}
			//ejecuta
			execvp(cmds[i][0], cmds[i]);
			//si falla, exit
			exit(1);
		}
		//proceso padre
		//cierra prev_fd
		if (prev_fd != -1)
				close(prev_fd);
		//si hay siguiente comando
		if (cmd[i + 1])
		{
			//cerrar pipe de escritura
			//guarda stdin en fd[0]
			close(pipefd[1]);
			prev_fd = pipefd[0];
		}
		i++;
	}
	// espera procesos hijos
	while (wait(&status) != -1)
	{
		// si algun hijo sale != 0; exitcode = 1;
		if (WIFEXITED(status) && WEXITSTATUS(status))
			exit_code = 1;
	}
	return (exit_code);
}
