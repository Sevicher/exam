#include <unistd.h>

int	f_v(char *str)
{
	int i;
	int	sstr;

	i = 0;
	sstr = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != '\n' && str[i] != 32)
			return (i);
		++i;
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int	i;
	int sin;

	i = 0;
	sin = 0;
	if (argc == 2)
	{
		if ((sin = f_v(argv[1])) >= 0)
		{
			while (argv[1][sin + i] && argv[1][sin + i] != '\t' && argv[1][sin + i] != '\n' && argv[1][sin + i] != 32)
			{
				write(1, &argv[1][sin + i], 1);
				++i;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
