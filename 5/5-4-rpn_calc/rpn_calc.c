#include <stdio.h>
#include <stdlib.h>

int	is_sign(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int	valid(char *str)
{
	int i;
	int flag;
	int op;
	int num;
	int error;

	i = -1;
	flag = 0;
	error = 0;
	op = 0;
	num = 0;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9' && flag == 0)
		{
			flag = 1;
			++num;
		}
		else if (str[i] == ' ' && str[i + 1] == '\0')
			error = 1;
		else if (str[i] == ' ' && flag == 1)
			flag = 0;
		else if (str[i] == ' ' && flag == 0)
			error = 1;
		else if (is_sign(str[i]))
		{
			flag = 1;
			++op;
		}
		else if (!(str[i] >= '0' && str[i] <= '0'))
			error = 1;
	}
	if (num - 1 != op)
		error = 1;
	if (error == 1)
	{
		printf("Error\n");
		return (0);
	}
	else
		return (1);
}

int	calc(char c, int a, int b)
{
	if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	else if (c == '*')
		return (a * b);
	else if (c == '/')
		return (a / b);
	else if (c == '%')
		return (a % b);
	return (0);
}

void	rpn_calc(char *str)
{
	int	NUM[2048];
	int	res;
	int	pop;

	pop = 0;
	if (!valid(str))
		return ;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			NUM[++pop] = atoi(str);
		else if (is_sign(*str))
		{
			res = calc(*str, NUM[pop - 1], NUM[pop]);
			NUM[--pop] = res;
		}
		str++;
	}
	printf("%d\n", NUM[1]);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rpn_calc(argv[1]);
	else
		printf("Error\n");
	return (0);
}
