#include "./big_pal.h"
#include <stdio.h>

int	is_word(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	pal_odd_even(char *str, int i, int flag)
{
	int k;
	int len;

	len = 0;
	k = i + 1;
	if (is_word(str[i]) && flag == 0)
	{
		len = 1;
		--i;
	}
	while (i >= 0 && str[k] && is_word(str[i]) && str[i] == str[k])
	{
		len += 2;
		++k;
		--i;
	}
	return (len);
}

void	big_pal(char *str)
{
	int	i;
	int	len;
	int	lenii;
	t_pal	polka;

	polka.i = 0;
	polka.len = 0;
	i = 0;
	len = 0;
	while (str[i])
	{
		len = (pal_odd_even(str, i, 0));
		lenii = (pal_odd_even(str, i, 1));
		if (lenii >= polka.len)
		{
			polka.len = lenii;
			polka.i = i - (lenii / 2 - 1);
		}
		if (len >= polka.len)
		{
			polka.len = len;
			polka.i = i - (len / 2);
		}
		++i;
	}
	lenii = polka.i + polka.len;
	while (polka.i < lenii)
	{
		write(1, &str[polka.i], 1);
		++polka.i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0])
		big_pal(argv[1]);
	write(1, "\n", 1);
	return (0);
}
