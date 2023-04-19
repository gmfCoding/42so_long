#include "map.h"

t_tile	new_tile(int id)
{
	t_tile tile;
	
	tile.id = id;
	tile.collectale = 0;
	return (tile);
}

t_tile new_c_tile(int floor, int collectable)
{
	t_tile	tile;

	tile = new_tile(floor);
	tile.collectale = collectable;
	return (tile);
}
