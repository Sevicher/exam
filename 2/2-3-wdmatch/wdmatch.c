#include <unistd.h>

void	wdmatch(char *str, char *str2)
{
	int i;
	int j;
	int k;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str2[k + j])
		{
			if (str[i] == str2[k + j])
			{
				k += j + 1;
				break;
			}
			else if (str2[k + j + 1] == '\0')
				flag = 1;
			++j;
		}
		++i;
	}
	if (flag ==1)
		return ;
	while (*str)
	{
		write(1, str, 1);
		++str;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
