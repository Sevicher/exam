#include <unistd.h>

int     is_space(char c)
{
	 if (c == '\n' || c == ' ' || c == '\v')
		 return (1);
	 return (0);
}

int		last_ind(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	--i;
	while (is_space(str[i]))
		--i;
	return (i);
}

void	epur_str(char *str)
{
	int i;
	int l_ind;

	i = 0;
	l_ind = last_ind(str);
	if (l_ind < 0)
		return ;
	while (is_space(str[i]))
		++i;
	if (i > l_ind)
		return ;
	while (i <= l_ind)
	{
		if (is_space(str[i]))
			write(1, " ", 1);
		while (is_space(str[i]) && (i <= l_ind))
			++i;
		while (!is_space(str[i]) && (i <= l_ind))
		{
			write(1, &str[i], 1);
			++i;
		}
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
