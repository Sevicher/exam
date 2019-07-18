#include <stdio.h>
#include <stdlib.h>

void	fprime(unsigned int num)
{
	int i;

	i = 2;
	if (num == 1)
		printf("1");
	else
	{
		while (num > 1)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				num = num / i;
				if (num > 1)
					printf("*");
				--i;
			}
			++i;
		}
	}
}	

int	main(int argc, char **argv)
{
	if (argc == 2 && *argv[1])
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
