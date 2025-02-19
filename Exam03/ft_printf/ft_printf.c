#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c, int *bytes)
{
	if (write(1, &c, 1) == -1)
		bytes = -1;
	else
		*(bytes++);
}

void	ft_fillformat(char *str, va_list lst, int *bytes)
{
	//%s , %d , %x
	if (str[*bytes + 1] == 's')
		va_arg(lst, char);
	else if (str[*bytes + 1] == 'd')
		va_arg(lst, int);
	else if (str[*bytes + 1] == 'x')
		va_arg(lst, char *);
	else
		ft_putchar('%', bytes);

}

int	ft_printf(char *str, ...)
{
	int		i;
	int		bytes;
	va_list	lst;

	i = 0;
	bytes = 0;
	va_start(lst, str);
	while (str[i] && bytes != -1)
	{
		if (str[i] == '%')
		{
			ft_fillformat(str);
		}
		else
			ft_putchar(str[i], &bytes);
	}
	i++;
	va_end(lst);
	return (bytes);
}

int	main(void)
{
	char	*str;
	int		num;

	str = "Hola";
	num = 42;
	ft_printf("%s from %d\n %d%d\n", str, num, num, num);
	printf("%s from %d\n %d%d\n",str, num, num, num);
	return (0);
}
