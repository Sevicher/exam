#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int *res;
	int i;
	int len;

	i = 0;
	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	res = (int*)malloc(sizeof(int) * len);
	if (start <= end)
	{
		while (start <= end)
		{
		res[i] = start;
		++start;
		++i;
		}
	}
	else
	{
		while (start >= end)
		{
		res[i] = start;
		--start;
		++i;
		}
	}
	return (res);
}
