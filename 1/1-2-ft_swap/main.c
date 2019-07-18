#include <stdio.h>

void    ft_swap(int *a, int *b);

int		main(void)
{
	int a = 1;
	int b = 5;

	printf("%d\t %d\n", a, b);
	ft_swap(&a, &b);
	printf("%d\t %d\n", a, b);
	return (0);
}
