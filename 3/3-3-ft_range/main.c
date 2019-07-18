#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end);

int		main(int argc, char **argv)
{
	int i;
	int *pr = NULL;

	i = 0;
	if (argc == 4)
	{
		pr = ft_range(atoi(argv[1]), atoi(argv[2]));
		while (i < atoi(argv[3]))
		{
			printf("%d", pr[i]);
			++i;
		}
	}
	printf("\n");
	return (0);
}
