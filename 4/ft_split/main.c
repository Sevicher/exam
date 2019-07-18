#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str);

int		main(int argc, char **argv)
{
	int i;
	char **res = NULL;

	i = 0;
	if (argc == 3)
	{
		res = ft_split(argv[1]);
		if (argv[2][0] == '1')
		{	
			while (res[i])
			{
				printf("%s\n", res[i]);
				++i;
			}
		}
	}
	else
		printf("\n");
	return (0);
}
