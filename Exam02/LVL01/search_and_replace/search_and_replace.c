#include <unistd.h>

void	search_and_replace(char *str, char *s1, char *s2)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] == s1[0])
		{
			str[i] = s2[0];
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (!argv[2][1] && !argv[3][1])
		{
			search_and_replace(argv[1], argv[2], argv[3]);
		}
	}
	write(1, "\n", 1);
}
