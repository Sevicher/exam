#include <unistd.h>
#include <stdio.h>

char	*ft_strrev(char *str);

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_strrev(argv[1]));
	else
		write(1, "\n", 1);
	return (0);
}
