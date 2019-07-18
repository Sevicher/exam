#include <stdlib.h>
#include <unistd.h>

char	*match(char *str, int direction)
{
	int i;

	i = 0;
	while (1)
	{
		if (*str == '[')
			++i;
		else if (*str == ']')
			--i;
		if (i == 0)
			return (str);
		str += direction;
	}
	return (NULL);
}

void	brainfuck(char *str)
{
	char *ptr;

	ptr = (char*)malloc(sizeof(char) * 2048);
	if (!ptr)
		return ;
	while (*str)
	{
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			(*ptr)++;
		else if (*str == '-')
			(*ptr)--;
		else if (*str == '.')
			write(1, ptr, 1);
		else if (*str == '[' && *ptr == 0)
			str = match(str, 1);
		else if (*str == ']' && *ptr)
			str = match(str, -1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0])
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
