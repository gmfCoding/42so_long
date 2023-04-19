#include "map.h"

t_tile	new_tile(int id)
{
	t_tile tile;
	
	tile.id = id;
	tile.collectable = 0;
	return (tile);
}

t_tile new_c_tile(int floor, int collectable)
{
	t_tile	tile;

	tile = new_tile(floor);
	tile.collectable = collectable;
	return (tile);
}
