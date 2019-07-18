#include <stdlib.h>

int		dig_len(int num)
{
	int count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		++count;
		num = num / 10;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int		n;
	int		sign;
	int		len;
	char	*str;

	n = 1;
	len = 0;
	sign = 0;
	if (nbr < 0)
	{
		sign = 1;
		++len;
		nbr *= -1;
	}
	len += dig_len(nbr);
	str = (char*)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	len = 0;
	if (sign == 1)
	{
		str[len] = '-';
		++len;
	}
	while (nbr / 10 >= n)
		n *= 10;
	while (n != 0)
	{
		str[len] = nbr / n + '0';
		++len;
		nbr = nbr % n;
		n /= 10;
	}
	return (str);
}
