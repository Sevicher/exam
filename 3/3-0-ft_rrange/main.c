#include <stdio.h>

int     *ft_rrange(int start, int end);

int		main(void)
{
	int i;
	int	*pr;

	i = -1;
	pr = ft_rrange(0, -3);
	while (++i <= 3)
		printf("%d\n", pr[i]);
	return (0);
}
