#include "unistd.h"

void	rotone(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Y')
			str[i] += 1;
		else if (str[i] == 'Z')
			str[i] = 'A';
		else if (str[i] >= 'a' && str[i] <= 'y')
			str[i] += 1;
		else if (str[i] == 'z')
			str[i] = 'a';
		write(1, &str[i], 1);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
