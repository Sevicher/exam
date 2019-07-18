#include <unistd.h>
# define BUFF_SIZE 2048

int	correct(char a, char b)
{
	return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'));
}

void	brackets(char *str)
{
	int	i;
	int	lvl;
	char	BR[BUFF_SIZE];

	i = 0;
	lvl = 0;
	if (!str || !*str)
	{
		write(1, "OK\n", 3);
		return ;
	}
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			BR[++lvl] = str[i];
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (correct(BR[lvl], str[i]))
				--lvl;
			else
			{
				write(1, "Error\n", 6);
				return ;
			}
		}
		++i;
	}
	if (lvl != 0)
		write(1, "Error\n", 6);
	else
		write(1, "OK\n", 3);
}


int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 1)
		while (++i < argc)
			brackets(argv[i]);
	else
		write(1, "\n", 1);
	return (0);
}
