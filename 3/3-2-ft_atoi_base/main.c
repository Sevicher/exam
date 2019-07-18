#include <stdio.h>
#include <stdlib.h>

int     ft_atoi_base(const char *str, int str_base);

int		main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d", ft_atoi_base(argv[1], atoi(argv[2])));
	printf("\n");
	return (0);
}
