int	main(int ac, char **av)
{
	// el input que va al ejecutar el programa.  ./a.out /bin/ls "|" grep pico
	if (ac < 2)
		return (1);

	//contar comandos, pipes
	int	cmd_count = countcmd(ac, av);
	char ***cmd = (char ***)malloc(sizeof(char **) * cmd_count + 1);
	if (!cmd)
		return (1);

	// introducir punteros a argumentos en nuestro ***array
	int	i = 1;
	int j = 0;
	// por cada av[i] (comando completo. av[0] = ["/bin/ls"], [NULL] av[1] = ["grep"], ["picoshell"], [NULL]...)
	while (i < ac)
	{
		int len = 0;
		//calculamos len. 1º iteracion.(av[1 + 0] < ac != "|")
		//len se resetea cada vez que se inica el bucle, por lo que i mantiene la posicion en el comando, y len
		// es el numero de argumentos de cada comando.
		while (i + len < ac && strcmp(av[i + len], "|") != 0)
			len++;
		// j = 0; j es el iterador del array en cada comando. cmd[j] es el array donde se guarda.
		//cmd[0] ="ls"
		//cmd[1] = "wc -e"
		cmd[j] = (char **)malloc(sizeof(char *) * (len + 1));
		if (!cmd[j])
			return (1);
		// bucle donde guardamos punteros hacia el input en nuestro array
		// cmd[0][0] = 'ls' av[1 + 0]
		int k = -1;
		while (++k < len)
			cmd[j][k] = av[i + k];
		cmd[j][len] = NULL;
		// i + len + 1 = ls -l | wc -e
		// primera iteracion i = 1 + 2 + 1; 
		// len = 2 porque ["ls", "-l"]
		// len + "|" siguiente posicion de la pipe.
		i = i + len + 1;
		//acabamos de copiar, sumamos j siguiente array.
		j++;
	}
	cmd[cmd_count] = NULL;
	int ret = picoshell(cmd);
	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
	return (ret);
}
