#include <stdlib.h>
#include <stdio.h>

void	pgcd(int small, int big)
{
	int del;
	int res;
	int temp;

	del = 1;
	res = 1;
	temp = 0;
	if (small > big)
	{
		temp = small;
		small = big;
		big = temp;
	}
	while (del <= small)
	{
		if (small % del == 0 && big % del == 0)
			res = del;
		++del;
	}
	printf("%d\n", res);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	else
		printf("\n");
	return (0);
}
