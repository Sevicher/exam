#include <unistd.h>

void	putnbr(int n)
{
	if (n > 9)
		putnbr(n / 10);
	n = n % 10 + '0';
	write(1, &n, 1);
}

int		main(int argc, char **argv)
{
	int n;

	*argv = NULL;
	n = argc - 1;
	putnbr(n);
	write(1, "\n", 1);
	return (0);
}
