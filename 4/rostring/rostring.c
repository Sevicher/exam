#include <unistd.h>

int		is_space(char c)
{
	if (c == 32 || c == '\n' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int		find_word(char *str, int n_word)
{
	int i;
	int res;
	int flag;
	int	w_count;

	i = 0;
	res = -1;
	flag = 0;
	w_count = 0;
	while (str[i])
	{
		if ((!is_space(str[i])) && flag == 0)
		{
			res = i;
			flag = 1;
			++w_count;
		}
		if (n_word == w_count)
			break ;
		if (is_space(str[i]))
			flag = 0;
		++i;
	}
	return (res);
}

void	rostring(char *str)
{
	int i;
	int j;
	int l_ind;

	i = find_word(str, 2);
	j = i;
	l_ind = find_word(str, 1);
	if (l_ind == -1)
		return ;
	while (str[i])
	{
		if (!(is_space(str[i])))
			write(1, &str[i], 1);
		else if (is_space(str[i]) && (!is_space(str[i + 1])) && str[i + 1])
			write(1, " ", 1);
		++i;
	}
	if (l_ind < j)
		write(1, " ", 1);
	while (l_ind < j && (!is_space(str[l_ind])))
	{
		write(1, &str[l_ind], 1);
		++l_ind;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
