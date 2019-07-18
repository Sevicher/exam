#include <unistd.h>

int		ft_atoi(char *str)
{
	int res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		++str;
	}
	return (res);
}

void	print_hex(int num)
{
	if (num > 15)
		print_hex(num / 16);
	num = num % 16;
	num += num < 10 ? '0' : 'a' - 10;
	write(1, &num, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
