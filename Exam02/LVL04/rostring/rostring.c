#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int start;
	int end;
	if (argc > 1)
	{
		i = 0;
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		start = i;
		while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
		{
			end = i;
			i++;
		}
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		while (argv[1][i])
		{
			while (argv[1][i] == ' ' && argv[1][i + 1] == ' ')
				i++;
			if (argv[1][i + 1] == '\0')
			{
				if (argv[1][i] != ' ')
					write(1, &argv[1][i], 1);
				write(1, " ", 1);
			}
			else
				write(1, &argv[1][i], 1);
				i++;
		}
		while (argv[1][start] && (start <= end))
		{
			write(1, &argv[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
}
