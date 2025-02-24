#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c, int *bytes)
{
	if (*bytes == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*bytes = -1;
	else
		(*bytes)++;
}

void	ft_putnbr(long n, char *str, int *bytes)
{
	if (*bytes == -1)
		return ;
	if (n < 0)
	{
		ft_putchar('-', bytes);
		n *= -1;
	}
	if (n < 10)
		ft_putchar(str[n], bytes);
	else
	{
		ft_putnbr(n / 10, str, bytes);
		ft_putnbr(n % 10, str, bytes);
	}
}

void	ft_puthex(unsigned int n, char *str, int *bytes)
{
	if (*bytes == -1)
		return ;
	if (n < 16)
		ft_putchar(str[n], bytes);
	else
	{
		ft_puthex(n / 16, str, bytes);
		ft_puthex(n % 16, str, bytes);
	}
}

void	ft_putstr(char *str, int *bytes)
{
	int	i;

	i = 0;
	if (*bytes == -1)
		return ;
	if (!str)
		str = "(null)";
	while (str[i])
		ft_putchar(str[i++], bytes);
}

void	ft_fillformat(va_list lst, char c, int *bytes)
{
	if (c == 'd')
		ft_putnbr(va_arg(lst, int), "0123456789", bytes);
	else if (c == 's')
		ft_putstr(va_arg(lst, char *), bytes);
	else if (c == 'x')
		ft_puthex(va_arg(lst, unsigned int), "0123456789abcdef", bytes);
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
			ft_fillformat(lst, str[++i], &bytes);
		else
			ft_putchar(str[i], &bytes);
		i++;
	}
	va_end(lst);
	return (bytes);
}
