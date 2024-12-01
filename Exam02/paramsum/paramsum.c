#include <unistd.h>

void	putnbr(int n)
{
	char str[11] = "0123456789";

	if (n > 9)
		putnbr(n / 10);
	write(1, &str[n % 10], 1);
}

int	main(int argc, char **argv)
{
	int i = 0;

	i = (argc - 1);

	if (argv)
	{
		putnbr(i);
		write(1, "\n", 1);
	}
	return (0);
}
