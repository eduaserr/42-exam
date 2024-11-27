#include <stdlib.h>

int	countwords(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
				i++;
			count++;
		}
		else if (str[i])
		{
			while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
				i++;
		}
	}
	return (count);
}

char	*ft_getword(char *str, int start, int end)
{
	char	*word;
	int	j;

	word = (char *)malloc((sizeof(char) * (end - start)) + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (str[start] && (start <= end))
	{
		word[j] = str[start];
		j++;
		start++;
	}

	word[j] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int	i = 0;
	int	j;
	int	start = 0;
	int	end = 0;
	int	nwords = countwords(str);
	char	**arr;

	arr = (char **)malloc((sizeof(char *) * nwords) + 1);
	if (!arr)
		return (NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	j = 0;
	while (nwords > 0)
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			start = i;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
			end = i - 1;
			arr[j] = ft_getword(str, start, end);
			j++;
			nwords--;
		}
		else if (str[i])
		{
			while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
				i++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
