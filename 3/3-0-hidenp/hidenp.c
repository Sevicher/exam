#include <unistd.h>

void	hidenp(char *needle, char *where)
{
	while (*where)
		if (*needle == *where++)
			++needle;
	(*needle == '\0') ? write(1, "1", 1) : write(1, "0", 1);

}

int		main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
