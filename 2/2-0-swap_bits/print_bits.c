#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;
	char temp;

	i = 8;
	while (--i >= 0)
	{
		temp = ((octet & (1 << i)) ? '1' : '0');
		write(1, &temp, 1);
	}
}
