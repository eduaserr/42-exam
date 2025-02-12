#include <unistd.h>

int	atoi(char *str)
{
	int i = 0;
	int n = 0;

	while (str[i])
	{
		if (i >= 1)
			n = n * 10;
		n += (str[i] - '0');
		i++;
	}
	return (n);
}

void	print_hex(int n)
{
	char base[17] = "0123456789abcdef";

	if (n > 15)
		print_hex(n / 16);
	write(1, &base[n % 16], 1);
}

int	main(int argc, char **argv)
{
	int n = 0;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		print_hex(n);
	}
	write(1, "\n", 1);
}
