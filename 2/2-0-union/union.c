#include <unistd.h>

void	inter(char *str1, char *str2)
{
	char exp[4096];
	int stack;
	int i;
	int j;
	int flag;

	stack = 0;
	flag = 0;
	exp[0] = '\0';
	i = 0;
	j = 0;
	while (str1[i])
	{
		j = 0;
		while (exp[j])
		{
			if (str1[i] == exp[j])
				flag = 1;
			++j;
		}
		if (flag == 0)
		{
			write(1, &str1[i], 1);
			exp[stack] = str1[i];
			exp[stack + 1] = '\0';
			++stack;
		}
		flag = 0;
		++i;
	}
	i = 0;
	j = 0;
	while (str2[i])
	{
		j = 0;
		while (exp[j])
		{
			if (str2[i] == exp[j])
				flag = 1;
			++j;
		}
		if (flag == 0)
		{
			write(1, &str2[i], 1);
			exp[stack] = str2[i];
			exp[stack + 1] = '\0';
			++stack;
		}
		flag = 0;
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
