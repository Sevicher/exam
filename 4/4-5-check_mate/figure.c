#include "checkmate.h"

int	pawn(int x, int y, char **map, int side)
{
	if (x - 1 >= 0 && y - 1 > 0 && map[y - 1][x - 1] == 'K')
		return (1);
	else if (x + 1 >= 0 && y - 1 < side && map[y - 1][x + 1] == 'K')
		return (1);
	else
		return (0);
}

int	bishop_solver(int x, int y, char **map, int side, int direction)
{
	int i;
	int k;

	if (direction == 0)
	{
		i = -1;
		k = -1;
	}
	else if (direction == 1)
	{
		i = 1;
		k = -1;
	}
	else if (direction == 2)
	{
		i = 1;
		k = 1;
	}
	else if (direction == 3)
	{
		i = -1;
		k = 1;
	}
	if (y > 0 && x >= 0 && x < side && y < side && map[y][x] == 'K')
		return (1);
	else if (y > 0 && x >= 0 && x < side && y < side && map[y][x] == '.')
		return (bishop_solver(x + i, y + k, map, side, direction));
	return (0);
}

int	bishop(int x, int y, char **map, int side)
{
	if (bishop_solver(x - 1, y - 1, map, side, 0))
		return (1);
	else if (bishop_solver(x + 1, y - 1, map, side, 1))
		return (1);
	else if (bishop_solver(x + 1, y + 1, map, side, 2))
		return (1);
	else if (bishop_solver(x - 1, y + 1, map, side, 3))
		return (1);
	else
		return (0);
}

int	rook_solver(int x, int y, char **map, int side, int direction)
{
	int i;
	int k;
	
	i = 0;
	k = 0;
	if (direction == 0)
		k = -1;
	else if (direction == 1)
		i = 1;
	else if (direction == 2)
		k = 1;
	else if (direction == 3)
		i = -1;
	if (y > 0 && x >= 0 && x < side && y < side && map[y][x] == 'K')
		return (1);
	else if (y > 0 && x >= 0 && x < side && y < side && map[y][x] == '.')
		return (rook_solver(x + i, y + k, map, side, direction));
	else
		return (0);
}

int	rook(int x, int y, char **map, int side)
{
	if (rook_solver(x, y - 1, map, side, 0))
		return (1);
	else if (rook_solver(x + 1, y, map, side, 1))
		return (1);
	else if (rook_solver(x, y + 1, map, side, 2))
		return (1);
	else if (rook_solver(x - 1, y, map, side, 3))
		return (1);
	else
		return (0);
}
