#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int end = 0;
	int start = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			i++;
		}
		i = i - 1;
		end = i;
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
		{
			i--;
			end = i;
		}
		while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
		{
			start = i;
			i--;
		}
		while (argv[1][start] && start <= end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
}
