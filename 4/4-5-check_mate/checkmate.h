#ifndef CHECKMATE_H
# define CHECKMATE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int     pawn(int x, int y, char **map, int side);
int     bishop_solver(int x, int y, char **map, int side, int direction);
int     bishop(int x, int y, char **map, int side);
int     rook_solver(int x, int y, char **map, int side, int direction);
int     rook(int x, int y, char **map, int side);

#endif
