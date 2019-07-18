#include <stdio.h>

char    *ft_strdup(char *src);

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_strdup(argv[1]));
	else
		printf("enter one argument\n");
	return (0);
}
