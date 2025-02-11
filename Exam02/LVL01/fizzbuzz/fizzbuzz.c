#include <unistd.h>
void	putnbr(int nb)
{
	char c[10] = "0123456789";
	if (nb > 9)
		putnbr(nb / 10);
	write(1, &c[nb % 10], 1);
}
int	main(void)
{
	int	i = 1;

	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 9);
		else if (i % 5 == 0)
			write(1, "buzz", 5);
		else if (i % 3 == 0)
			write(1, "fizz", 5);
		else
			putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}
