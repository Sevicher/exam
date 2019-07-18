#include <stdio.h>

int		ft_strlen(char *str);

int		main(void)
{
	int count;
	char str[] = "HelloWorld";

	count = ft_strlen(str);
	printf("%d\n", count);
	return (0);
}