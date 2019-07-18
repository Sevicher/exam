#include <stdio.h>

void    sort_int_tab(int *tab, unsigned int size);

int		main(void)
{
	int i;
	int lol[6] = {10, 9, 8, 8, 7, 6};

	i = 0;
	sort_int_tab(lol, 6);
	while (i < 6)
	{
		printf("%d ", lol[i]);
		++i;
	}
	printf("\n");
	return (0);
}
