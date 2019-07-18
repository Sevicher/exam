#include <unistd.h>

void	inter(char *exp, char *find)
{
	int i;
	int j;
	int flag;
	char used[128];

	i = 0;
	j = 0;
	flag = 0;
	used[0] = '\0';
	while (*exp)
	{
		i = 0;
		j = 0;
		while (find[i])
		{
			if (*exp == find[i])
			{
				while (used[j])
				{
					if (used[j] == *exp)
						flag = 1;
					++j;
				}
				if (flag == 0)
				{
					write(1, exp, 1);
					used[j] = *exp;
					used[j + 1] = '\0';
					break ;
				}
			}
			flag = 0;
			j = 0;
			++i;
		}
		flag = 0;
		++exp;
	}

}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
