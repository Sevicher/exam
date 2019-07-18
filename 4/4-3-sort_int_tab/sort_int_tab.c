void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = 1;
	temp = 0;
	while (i < size)
	{
		while (i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
			}
			++i;
		}
		i = 1;
		--size;
	}
}
