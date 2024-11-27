#include <unistd.h>

void	ft_putstr(char *str)
{
	int i = 0;

	if (!str || !str[i])
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
