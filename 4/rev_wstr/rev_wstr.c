#include <unistd.h>

int		is_space(char c)
{
	if (c == 32 || c == '\n' || c == '\t' ||c == '\v')
		return (1);
	return (0);
}

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	--i;
	return (i);
}

void	print_word(char *str)
{
	while ((!is_space(*str)) && *str)
	{
		write(1, str, 1);
		++str;
	}
}

void	rev_wstr(char *str)
{
	int i;
	int j;
	int flag;

	j = 0;
	flag = 0;
	i = ft_len(str);
	while (i >= 0)
	{
		if (!is_space(str[i]))
			flag = 1;
		if (flag == 1 && (i == 0))
		{
			print_word(&str[i]);
			--i;
			flag = 0;
			continue ;
		}
		if (flag == 1 && is_space(str[i - 1]))
		{
			print_word(&str[i]);
			write(1, " ", 1);
			--i;
			flag = 0;
			continue ;
		}
		--i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
