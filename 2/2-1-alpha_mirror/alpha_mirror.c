#include <unistd.h>

void	alpha_mirror(char *str)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			temp = str[i] - 97;
			str[i] = 122 - temp;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			temp = str[i] - 65;
			str[i] = 90 - temp;
		}
		write(1, &str[i], 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}
