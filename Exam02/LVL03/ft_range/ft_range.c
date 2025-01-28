#include <unistd.h>
#include <stdlib.h>

int	ft_max(int start, int end)
{
	if (start < end)
		return (end - start);
	return (start - end);
}

int	*ft_range(int start, int end)
{
	int *tab;
	int len;
	int	i;

	len = ft_max(start, end);
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	i = 0;
	while (i <= len)
	{
		tab[i] = start;
		if (start < end)
			start++;
		else
			start--;
		i++;
	}
	return (tab);
}
