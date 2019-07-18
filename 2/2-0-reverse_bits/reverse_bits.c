unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char res;

	i = -1;
	res = octet;
	while (++i < 8)
		res = (res << 1) | ((octet >> i) & 1);
	return (res);
}
