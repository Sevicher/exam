#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2);

int 	main(void)
{
	char 	s1[11];
	char 	s2[] = "HelloWorld";
	char 	*s;

	s = ft_strcpy(s1, s2);
	printf("%s\n", s);
	return (0);
}