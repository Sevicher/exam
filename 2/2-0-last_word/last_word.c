#include <unistd.h>

int	word_or_not(char c)
{
	if (c == '\t' || c == '\n' || c == 32)
		return (0);
	return (1);
}

int	ind_last_word(const char *str)
{
	int i;
	int current_word;

	i = 0;
	current_word = -1;
	while (str[i])
	{
		if (word_or_not(str[i]))
			current_word = i;
		while (str[i] && word_or_not(str[i]))
			++i;
		while (str[i] && !word_or_not(str[i]))
			++i;
	}
	return (current_word);
}

void	last_word(const char *str)
{
	int i;

	if ((i = ind_last_word(str)) >= 0)
	while (str[i] && word_or_not(str[i]))
	{
		write(1, &str[i], 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
