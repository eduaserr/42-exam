#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	int i = -1;

	if (argc > 1)
	{
		while (++i < ft_strlen(argv[argc - 1]))
			write(1, &argv[argc - 1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
