#include "checkmate.h"

char	*new_str(int len)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
		str[len] = '0';
	return (str);
}

int	check(char c, int x, int y, char **map, int side)
{
	if (c == 'P')
		return (pawn(x, y, map, side));
	else if (c == 'B')
		return (bishop(x, y, map, side));
	else if (c == 'R')
		return (rook(x, y, map, side));
	else if (c == 'Q')
		return (rook(x, y, map, side) || bishop(x, y, map, side));
	return (0);
}

void	solver(char **map, int side)
{
	int y;
	int x;

	y = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '.' && map[y][x] != 'K')
			{
				if (check(map[y][x], x, y, map, side))
				{
					printf("Succes\n");
					return ;
				}
			}
			++x;
		}
	}
	printf("Fail\n");
}

int	main(int argc, char **argv)
{
	if (argc > 1 && (argc - 1) % 2 == 0)
		solver(argv, argc - 1);
	else
		printf("Fail\n");
	return (0);
}
