#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int		ft_atosha(char *str)
{
	int res;

	res = 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res);
}

void	tab_mult(int n)
{
	int i;

	i = 1;
	while (i < 10)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		write(1, "\n", 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(ft_atosha(argv[1]));
	else
		write(1, "\n", 1);
	return (0);
}
