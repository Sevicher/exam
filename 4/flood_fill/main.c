#include "flood_fill.h"

void	print_map(char map[10][10], int x, int y)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
}

int	is_correct(char c, char map[10][10], t_point map_size, int x, int y)
{
	if (x >= 0 && y >= 0 && x < map_size.x && y < map_size.y)
		if ( map[y][x] == c)
			return (1);
	return (0);
}

void	recursive_flood(char c, char map[10][10], t_point map_size, int x, int y)
{
	if (is_correct(c, map, map_size, x + 1, y))
	{
		map[y][x + 1] = 'F';
		recursive_flood(c, map, map_size, x + 1, y);
	}
	if (is_correct(c, map, map_size, x, y + 1))
	{
		map[y + 1][x] = 'F';
		recursive_flood(c, map, map_size, x, y + 1);
	}
	if (is_correct(c, map, map_size, x - 1, y))
	{
		map[y][x - 1] = 'F';
		recursive_flood(c, map, map_size, x - 1, y);
	}
	if (is_correct(c, map, map_size, x, y - 1))
	{
		map[y - 1][x] = 'F';
		recursive_flood(c, map, map_size, x, y - 1);
	}
}

void	flood_fill(char map[10][10], t_point map_size, t_point start)
{
	char c;

	c = '\0';
	if (start.x - 1 < map_size.x && start.y - 1 < map_size.y)
	{
		c = map[start.y - 1][start.x -1];
		map[start.y - 1][start.x -1] = 'F';
		recursive_flood(c, map, map_size, start.x - 1, start.y - 1);
	}
	else
		return ;
}

int	main(void)
{
	int x = 10;
	int y = 10;
	char map[10][10] = {{'0', '0', '1', '1', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '1', '1', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '1', '1', '0', '0', '1', '1', '1', '1'},
			{'0', '0', '1', '1', '0', '0', '1', '1', '1', '1'},
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
			{'1', '1', '1', '1', '0', '0', '1', '1', '0', '0'},
			{'1', '1', '1', '1', '0', '0', '1', '1', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '1', '1', '0', '0'}};
	t_point map_size;
	t_point start;
	map_size.x = x;
	map_size.y = y;
	print_map(map, x, y);
	printf("map_size y = %d x = %d\n", map_size.y, map_size.x);
	printf("Enter y for point, where will be flood\n");
	start.y = getchar() - '0';
	write(1, "\n", 1);
	printf("Enter x for point, where will be flood\n");
	start.x = getchar() - '0';
	write(1, "\n", 1);
	printf("start y = %d x = %d\n", start.y, start.x);
	flood_fill(map, map_size, start);
	printf("map after flood\n");
	print_map(map, x, y);
	return (0);
}
