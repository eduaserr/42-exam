#include <unistd.h>

int	main()
{
	char	*str = "zYxWvUtSrQpOnMlKjIhGfEdCbA";
	int	i = -1;

	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
	return (0);
}
