#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\v' || str[i + 1] == '\0') && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		else if ((str[i + 1] != ' ' && str[i + 1] != '\n' && str[i + 1] != '\v' && str[i + 1] != '\0') && str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		write(1, &str[i], 1);
		++i;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
