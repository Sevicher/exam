#include <unistd.h>

int		cur_letter(char c)
{
	if (c >= 65 && c <= 90)
		return (c - 64);
	else if (c >= 97 && c <= 122)
		return (c - 96);
	else
		return (1);
}	

void	printer(char c, int counter)
{
	while (counter > 0)
	{
		write(1, &c, 1);
		--counter;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	counter;
	i = 0;
	counter = 1;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			printer(argv[1][i], cur_letter(argv[1][i]));
			++i;
		}
	}
	write(1, "\n", 1);
	return (0);
}
