int	max(int *tab, unsigned int len)
{
	int max;
	unsigned int i;
	
	i = 0;
	max = -2147483647;
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		++i;
	}
	return (max);
}
