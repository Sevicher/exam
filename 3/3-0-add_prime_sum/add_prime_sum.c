#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_atoi(char *str)
{
	int res;

	res = 0;
	if (*str == '-')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		++str;
	}
	return (res);
}

void	add_prime_sum(int num)
{
	int i;
	int j;
	int res;
	int flag;

	i = 1;
	j = 1;
	res = 0;
	flag = 0;
	while (i <= num)
	{
		j = 0;
		flag = 0;
		while (++j <= i)
		{
			if (i % j == 0)
				++flag;
		}
		if (flag == 2)
			res += i;
		++i;
	}
	ft_putnbr(res);
}

int	main(int argc, char **argv)
{
	int num;

	num = 0;
	if (argc == 2 && ((num = ft_atoi(argv[1])) != -1))
		add_prime_sum(num);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
