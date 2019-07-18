#include <unistd.h>

int		is_blank(char c)
{
	if (c == 32 || c == '\n' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	str_capitalizer(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && flag == 0)
		{
			str[i] = str[i] - 32;
			flag = 1;
		}
		else if ((!is_blank(str[i])) && flag == 0)
			flag = 1;
		else if (str[i] >= 'A' && str[i] <= 'Z' && flag == 1)
		{
			flag = 1;
			str[i] = str[i] + 32;
		}
		else if (is_blank(str[i]))
			flag = 0;
		write(1, &str[i], 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
