#include <unistd.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i = 0;
	int *tab;
	int len = end - start;

	tab = (int *)malloc(sizeof(int) * (len + 1));
	if (!tab)
		return (NULL);
	while (len >= 0)
	{
		tab[len] = start;
		start++;
		len--;
	}
	return (tab);
}