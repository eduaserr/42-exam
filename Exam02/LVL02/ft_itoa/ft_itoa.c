#include <stdlib.h>

size_t	int_len(int nbr)
{
	int i = 0;

	if (nbr < 0)
		i++;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long	n	= 0;
	size_t	len	= int_len(nbr);
	char	*str;

	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		str[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}
