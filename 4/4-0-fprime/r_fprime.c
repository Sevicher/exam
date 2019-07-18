#include <stdio.h>
#include <stdlib.h>

void	r_fprime(unsigned int n, unsigned int i)
{
	int k;

	k = 0;
	while (n % i != 0 && i < n)
		++i;
	if (n % i == 0)
	{
		printf("%d", i);
		k = n / i;
		if (k != 1)
			printf("*");
		if (n != i)
			r_fprime(k, i);
	}
	else
		printf("%d", n);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && *argv[1])
		r_fprime(atoi(argv[1]), 2);
	printf("\n");
	return (0);
}
