#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = ft_strlen(argv[1]);

		while (argv[1][--i] && i >= 0)
		{
			write(1, &argv[1][i], 1);
		}
	}
	write(1, "\n", 1);
}