#include <unistd.h>

void			print_bits(unsigned char octet);
unsigned char	reverse_bits(unsigned char octet);

int				main(int argc, char **argv)
{
	if (argc == 2)
	{
		print_bits((unsigned char)argv[1][0]);
		write(1, "\n", 1);
		print_bits(reverse_bits((unsigned char)argv[1][0]));
	}
	write(1, "\n", 1);
	return (0);
}
