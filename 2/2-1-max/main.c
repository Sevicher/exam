#include <stdio.h>

int	max(int *tab, unsigned int len);

int	main(void)
{
	unsigned int i;
	unsigned int len;
	int count;
	int tab[10];
	int res;

	i = 0;
	res = 0;
	len = 10;
	count = -150;
	while (i < 10)
	{
		tab[i] = count;
		++i;
		count += 100;
	}
	res = max(tab, len);
	printf("%d\n", res);
	return (0);
}
