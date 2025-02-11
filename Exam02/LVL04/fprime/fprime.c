#include <stdio.h>
#include <stdlib.h>

void	fprime(int nbr)
{
	int	i;

	i = 2;
	if (nbr == 1)
			printf("%d", nbr);
	while (nbr >= i)
	{
		while (nbr % i == 0)
		{
			nbr = nbr / i;
			if (nbr == 1)
				printf("%d", i);
			else
				printf("%d*", i);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		fprime(atoi(argv[1]));
	}
	printf("\n");
}
