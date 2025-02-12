#include <unistd.h>

int main(int argc, char **argv)
{
	char seen[256] = {0};
	int i;
	int j;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					if (!seen[argv[1][i]])
					{
						seen[argv[1][i]] = 1;
						write(1, &argv[1][i], 1);
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
