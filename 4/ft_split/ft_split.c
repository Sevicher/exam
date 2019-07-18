#include <stdlib.h>

int		is_space(char c)
{
	if (c == 32 || c =='\n' || c =='\t' || c =='\v')
		return (1);
	return (0);
}

int		word_len(char *str)
{
	int i;

	i = 0;
	while ((!is_space(str[i])) && str[i])
		++i;
	return (i);
}

int		word_counter(char *str)
{
	int flag;
	int count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (is_space(*str))
			flag = 0;
		if (flag == 0 && (!is_space(*str)))
		{
			++count;
			flag = 1;
		}
		++str;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int 	i;
	int 	j;
	int		k;
	int 	len;
	char	**res;

	i = 0;
	j = 0;
	k = 0;
	if (!(len = word_counter(str)))
		return (NULL);
	res = (char**)malloc(sizeof(char*) * len + 1);
	res[len] = NULL;
	while (str[i])
	{
		if (is_space(str[i]))
		{
			++i;
			continue ;
		}
		else
		{
			k = 0;
			len = word_len(&str[i]);
			res[j] = (char*)malloc(sizeof(char) * len + 1);
			res[j][len] = '\0';
			while (k < len)
			{
				res[j][k] = str[i];
				++i;
				++k;
			}
			++j;
		}
	}
	return (res);
}
