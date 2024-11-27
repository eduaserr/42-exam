int	ft_atoi(const char *str)
{
	int	i;
	int	negative = 1;
	int	n;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	n = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		n = n * 10;
		n += str[i] - '0';
		i++;
	}
	return (n * negative);
}
