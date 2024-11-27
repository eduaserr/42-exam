#include <unistd.h>

void	putnbr(int n)
{
	char str[11] = "0123456789";

	if (n > 9)
		putnbr(n / 10);
	write(1, &str[n % 10], 1);
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	n = 0;

	while (str[i])
	{
		if (i >= 1)
			n = n * 10;
		n += (str[i] - '0');
		i++;
	}
	return (n);
}

int	is_prime(int n)
{
	int i = 2;

	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	add_prime_sum(char *str)
{
	int res = 0;
	int n = 0;

	if (str && str[0] != '-')
	{
		n = ft_atoi(str);
		while (n > 1)
		{
			if (is_prime(n))
			{
				res = res + n;
			}
			n--;
		}
		putnbr(res);
	}
	else
		putnbr(0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		add_prime_sum(argv[1]);
	}
	else
		putnbr(0);
	write(1, "\n", 1);
}
