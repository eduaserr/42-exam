#include <unistd.h>

void	rotone(char *str)
{
	int i = 0;

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
		{
			str[i] += 1;
		}
		else if (str[i] == 'z')
			str[i] = 'a';
		else if (str[i] == 'Z')
			str[i] = 'A';
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		rotone(argv[1]);
		while(argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1,"\n",1);
}
