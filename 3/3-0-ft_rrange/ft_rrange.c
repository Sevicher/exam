#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int i;
	int	len;
	int	*res;

	if (start <= end)
	{
		i = 0;
		len = end - start + 1;
	}
	else
	{
		i = 1;
		len = start - end + 1;
	}
	res = (int*)malloc(sizeof(int) * len);
	if (i == 0)
	{
		while (i <= len)
		{
			res[i] = end;
			++i;
			--end;
		}
	}
	else
	{
		i = 0;
		while (i <= len)
		{
			res[i] = end;
			++i;
			++end;
		}
	}
	return (res);
}
