#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strcpy(char *dst, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *src)
{
	char *dst;

	dst = (char*)malloc(sizeof(ft_strlen(src)) + 1);
	return (ft_strcpy(dst, src));
}
