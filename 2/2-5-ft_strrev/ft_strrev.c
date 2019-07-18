int	last_ind(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	--i;
	return (i);
}


char	*ft_strrev(char *str)
{
	int left;
	int right;
	char temp;

	left = 0;
	right = last_ind(str);
	while (left < right)
	{
		temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		++left;
		--right;
	}
	return (str);
}
