#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int repeat;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			repeat = 0;
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				repeat = argv[1][i] - 'A';
			}
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				repeat = argv[1][i] - 'a';
			}
			while (repeat-- >= 0)
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
